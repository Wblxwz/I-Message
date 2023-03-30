#include <assert.h>
#include <random>
#include <string.h>
#include <iostream>

#include "sqloperate.h"

std::vector<info*> SqlOperate::shenQing(MYSQL* conn, const char* account)
{
	char sql[100];
	sprintf(sql, "SELECT * FROM adds WHERE t = '%s' AND state = '%s'", account, "w");
	int ret = mysql_real_query(conn, sql, strlen(sql));
	assert(ret == 0);
	MYSQL_RES* res = mysql_store_result(conn);
	MYSQL_ROW row;
	std::vector<info*> infos;
	while ((row = mysql_fetch_row(res)))
	{
		info* i = new info;
		i->from = row[0];
		i->to = row[1];
		i->state = row[2];
		i->yanzheng = row[3];
		i->name = row[4];
		infos.push_back(i);
	}
	return infos;
}

void SqlOperate::useDb(MYSQL* conn)
{
	std::string sql = "USE imessage";
	int ret = mysql_real_query(conn, sql.c_str(), sql.length());
	assert(ret == 0);
}

const char* SqlOperate::insert(MYSQL* conn, const std::string& username, const std::string& userpwd)
{
	std::default_random_engine e;
	std::uniform_int_distribution<size_t> u(100000, 999999);
	e.seed(time(nullptr));
	std::string account = std::to_string(u(e));
	char sql1[100] = { '0' };
	sprintf(sql1, "SELECT account FROM users WHERE account = '%s'", account.c_str());
	int ret = mysql_real_query(conn, sql1, strlen(sql1));
	assert(ret == 0);
	MYSQL_RES* res = mysql_store_result(conn);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		account = std::to_string(u(e));
		memset(sql1, '0', sizeof(sql1) / sizeof(char));
		sprintf(sql1, "SELECT account FROM users WHERE account = '%s'", account.c_str());
		ret = mysql_real_query(conn, sql1, strlen(sql1));
		assert(ret == 0);
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
	}
	char sql[100] = { '0' };
	sprintf(sql, "INSERT INTO users(account, pwd, name,state) VALUES ('%s', '%s', '%s','%s')", account.c_str(), userpwd.c_str(), username.c_str(), "false");
	ret = mysql_real_query(conn, sql, strlen(sql));
	assert(ret == 0);
	return account.c_str();
}

bool SqlOperate::search(MYSQL* conn, const std::string& account)
{
	char sql[100] = { '0' };
	sprintf(sql, "SELECT account FROM users WHERE account = '%s'", account.c_str());
	int ret = mysql_real_query(conn, sql, strlen(sql));
	MYSQL_RES* res = mysql_store_result(conn);
	MYSQL_ROW row = mysql_fetch_row(res);
	if (row)
		return true;
	return false;
}

const char* SqlOperate::searchName(MYSQL* conn, const char* account)
{
	char sql[100]{ '0' };
	sprintf(sql, "SELECT name FROM users WHERE account = '%s'", account);
	int ret = mysql_real_query(conn, sql, strlen(sql));
	assert(ret == 0);
	MYSQL_RES* res = mysql_store_result(conn);
	MYSQL_ROW row;
	if ((row = mysql_fetch_row(res)))
		return row[0];
	return mysql_error(conn);
}

void SqlOperate::updateState(MYSQL* conn, const char* account, bool state)
{
	char sql[100];
	if (state)
		sprintf(sql, "UPDATE users SET state = 'true' WHERE account = '%s'", account);
	else
		sprintf(sql, "UPDATE users SET state = 'false' WHERE account = '%s'", account);
	int ret = mysql_real_query(conn, sql, strlen(sql));
	assert(ret == 0);
}

void SqlOperate::add(MYSQL* conn, const char* from, const char* to, const char* yanzheng, const char* name)
{
	char sql[1024];
	sprintf(sql, "INSERT INTO adds(fr,t,state,info,name) VALUES('%s','%s','%s','%s','%s')", from, to, "w", yanzheng, name);
	int ret = mysql_real_query(conn, sql, strlen(sql));
	assert(ret == 0);
}

void SqlOperate::updateAdds(MYSQL* conn,const char* fr,const char* t, bool state)
{
	char sql[100];
	if (state)
		sprintf(sql, "UPDATE adds SET state = '%s' WHERE fr = '%s' AND t = '%s'", "y", fr, t);
	else
		sprintf(sql, "UPDATE adds SET state = '%s' WHERE fr = '%s' AND t = '%s'", "n", fr, t);
	int ret = mysql_real_query(conn, sql, strlen(sql));
	assert(ret == 0);
}
