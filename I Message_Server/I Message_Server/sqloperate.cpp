#include <assert.h>
#include <random>
#include <string.h>
#include <iostream>

#include "sqloperate.h"

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
	sprintf(sql, "INSERT INTO users(account, pwd, name) VALUES ('%s', '%s', '%s')", account.c_str(), userpwd.c_str(), username.c_str());
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
