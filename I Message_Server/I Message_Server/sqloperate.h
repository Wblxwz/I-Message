#pragma once

#include <mysql.h>
#include <string>

class SqlOperate
{
public:
	SqlOperate(){}
	~SqlOperate() {}

	void useDb(MYSQL* conn);
	const char* insert(MYSQL* conn, const std::string& username, const std::string& userpwd);
	bool search(MYSQL* conn, const std::string& account);
	const char* searchName(MYSQL* conn, const char* account);
};