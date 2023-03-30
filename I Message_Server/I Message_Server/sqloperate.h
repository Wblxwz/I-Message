#pragma once

#include <mysql.h>
#include <vector>
#include <string>

struct info
{
	info() :from(""), to(""), yanzheng(""), state(""), name("") {}
	const char* from;
	const char* to;
	const char* yanzheng;
	const char* state;
	const char* name;
};

class SqlOperate
{
public:
	SqlOperate() {}
	~SqlOperate() {}

	std::vector<info*> shenQing(MYSQL* conn, const char* account);
	void useDb(MYSQL* conn);
	const char* insert(MYSQL* conn, const std::string& username, const std::string& userpwd);
	bool search(MYSQL* conn, const std::string& account);
	const char* searchName(MYSQL* conn, const char* account);
	void updateState(MYSQL* conn, const char* account, bool state);
	void add(MYSQL* conn, const char* from, const char* to, const char* yanzheng, const char* name);
	void updateAdds(MYSQL* conn, const char* fr, const char* t,bool state);
};