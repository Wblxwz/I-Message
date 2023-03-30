#include <sys/socket.h>
#include <string.h>
#include <string>
#include <mysql.h>
#include <iostream>

#include "worker.h"
#include "connpool.h"
#include "connraii.h"
#include "server.h"

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
	if (s.find("name:") != -1)
	{
		ConnPool* pool = ConnPool::getPool();
		MYSQL* conn = nullptr;
		ConnRAII(pool, &conn);
		SqlOperate sql;
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
		ConnPool* pool = ConnPool::getPool();
		MYSQL* conn = nullptr;
		ConnRAII(pool, &conn);
		SqlOperate sql;
		char name[30];
		int x = 0;
		for (int i = 4; i < s.size(); ++i)
			name[x++] = s[i];
		addMap(cfd, name);
		char bbuf[100]{ '0' };
		sprintf(bbuf, sql.searchName(conn, name));
		send(cfd, bbuf, sizeof(bbuf), NULL);
		sql.updateState(conn, name, true);
		infos = sql.shenQing(conn, name);
		addInfos(infos);
		int n = infos.size();
		char buf[200];
		sprintf(buf, "n:");
		sprintf(buf + strlen(buf), "%d", n);
		send(cfd, buf, sizeof(buf), NULL);
		for (int i = 0; i < n; ++i)
		{
			char tbuf[200];
			sprintf(tbuf + strlen(tbuf), "from:");
			sprintf(tbuf + strlen(tbuf), infos[i]->from);
			sprintf(tbuf + strlen(tbuf), "name:");
			sprintf(tbuf + strlen(tbuf), infos[i]->name);
			sprintf(tbuf + strlen(tbuf), "info:");
			sprintf(tbuf + strlen(tbuf), infos[i]->yanzheng);
			send(cfd, tbuf, sizeof(tbuf), NULL);
		}
	}
	if (s.find("chazhao:") != -1)
	{
		ConnPool* pool = ConnPool::getPool();
		MYSQL* conn = nullptr;
		ConnRAII(pool, &conn);
		SqlOperate sql;
		char name[30];
		int x = 0;
		for (int i = 8; i < s.size(); ++i)
			name[x++] = s[i];
		char buf[50];
		sprintf(buf, sql.searchName(conn, name));
		send(cfd, buf, sizeof(buf), NULL);
	}
	if (s.find("out") != -1)
	{
		ConnPool* pool = ConnPool::getPool();
		MYSQL* conn = nullptr;
		ConnRAII(pool, &conn);
		SqlOperate sql;
		deleteFromCfds(cfd);
		sql.updateState(conn, getAccount(cfd), false);
	}
	if (s.find("from:") != -1)
	{
		ConnPool* pool = ConnPool::getPool();
		MYSQL* conn = nullptr;
		ConnRAII(pool, &conn);
		SqlOperate sql;
		std::string from, to, yanzheng, name;
		int nn = s.find("user:");
		for (int i = 5; i < nn; ++i)
			from.push_back(s[i]);
		int n = s.find("to:");
		for (int i = nn + 5; i < n; ++i)
			name.push_back(s[i]);
		int tn = s.find("yanzheng:");
		for (int i = n + 3; i < tn; ++i)
			to.push_back(s[i]);
		for (int i = tn + 9; i < s.size(); ++i)
			yanzheng.push_back(s[i]);
		sql.add(conn, from.c_str(), to.c_str(), yanzheng.c_str(), name.c_str());
	}
	if (s.find("tongyi") != -1)
	{
		ConnPool* pool = ConnPool::getPool();
		MYSQL* conn = nullptr;
		ConnRAII(pool, &conn);
		SqlOperate sql;
		std::string ss;
		for (int i = 6; i < s.size(); ++i)
			ss.push_back(s[i]);
		sql.updateAdds(conn, infos[atoi(ss.c_str())]->from, infos[atoi(ss.c_str())]->to, true);
	}
	if (s.find("jujue") != -1)
	{
		ConnPool* pool = ConnPool::getPool();
		MYSQL* conn = nullptr;
		ConnRAII(pool, &conn);
		SqlOperate sql;
		std::string ss;
		for (int i = 6; i < s.size(); ++i)
			ss.push_back(s[i]);
		sql.updateAdds(conn, infos[atoi(ss.c_str())]->from, infos[atoi(ss.c_str())]->to, false);
	}
}
