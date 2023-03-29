#include <sys/socket.h>
#include <string.h>
#include <string>
#include <mysql.h>
#include <iostream>

#include "worker.h"
#include "connpool.h"
#include "connraii.h"
#include "sqloperate.h"

void Worker::signUp(const std::string& s, char* name, char* pwd)
{
	int n = s.find("pwd:");
	int x = 0;
	for (int i = 5; i < n; ++i)
		name[x++] = s[i];
	x = 0;
	n += 4;
	for (int i = n; i < s.size(); ++i)
		pwd[x++] = s[i];
}

bool Worker::logIn(const std::string& s, char* account, char* pwd)
{
	int n = s.find("pwd:");
	int x = 0;
	for (int i = 8; i < n; ++i)
		account[x++] = s[i];
	x = 0;
	n += 4;
	for (int i = n; i < s.size(); ++i)
		pwd[x++] = s[i];
	ConnPool* pool = ConnPool::getPool();
	MYSQL* conn = nullptr;
	ConnRAII(pool, &conn);
	SqlOperate sql;
	return sql.search(conn, account);
}

Worker::~Worker()
{
}

void Worker::work()
{
	char buf[1024]{ '0' };
	recv(cfd, buf, sizeof(buf), NULL);

	std::string s(buf);
	char name[30]{ '0' };
	char account[6]{ '0' };
	char pwd[16]{ '0' };
	ConnPool* pool = ConnPool::getPool();
	MYSQL* conn = nullptr;
	ConnRAII(pool, &conn);
	SqlOperate sql;
	if (s.find("name:") != -1)
	{
		signUp(s, name, pwd);
		send(cfd, sql.insert(conn, name, pwd), 6, NULL);
	}
	if (s.find("account:") != -1)
	{
		char buf[10]{ '0' };
		char account[6]{ '0' };
		char pwd[16]{ '0' };
		if (logIn(s, account, pwd))
			sprintf(buf, "true");
		else
			sprintf(buf, "false");
		send(cfd, buf, sizeof(buf), NULL);
	}
	if (s.find("log:") != -1)
	{
		char name[30];
		int x = 0;
		for (int i = 4; i < s.size(); ++i)
			name[x++] = s[i];
		char buf[100]{ '0' };
		sprintf(buf, sql.searchName(conn, name));
		send(cfd, buf, sizeof(buf), NULL);
	}
	if (s.find("chazhao:") != -1)
	{
		char name[30];
		int x = 0;
		for (int i = 8; i < s.size(); ++i)
			name[x++] = s[i];
		char buf[50];
		sprintf(buf, sql.searchName(conn, name));
		send(cfd, buf, sizeof(buf), NULL);
	}
}
