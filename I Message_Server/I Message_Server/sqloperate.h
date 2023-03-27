#pragma once

#include <mysql.h>
#include <string>

class SqlOperate
{
public:
	SqlOperate(){}
	~SqlOperate() {}

	void useDb(MYSQL* conn);
	void insert(MYSQL* conn, const std::string& username, const std::string& userpwd);
	void search(MYSQL* conn, const std::string& account);
};