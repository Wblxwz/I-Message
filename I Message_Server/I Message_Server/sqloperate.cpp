#include <assert.h>
#include <random>

#include "sqloperate.h"

void SqlOperate::useDb(MYSQL* conn)
{
	std::string sql = "USE imessage";
	int ret = mysql_real_query(conn, sql.c_str(), sql.length());
	assert(ret == 0);
}

void SqlOperate::insert(MYSQL* conn, const std::string& username, const std::string& userpwd)
{
	std::default_random_engine e;
	std::uniform_int_distribution<size_t> u(100000,999999);
	std::string account = std::to_string(u(e));
	char sql[100] = { '0' };
	sprintf(sql, "INSERT INTO users(account, pwd, name) VALUES('%s', '%s', '%s')", account.c_str(), userpwd.c_str(), username.c_str());

}
