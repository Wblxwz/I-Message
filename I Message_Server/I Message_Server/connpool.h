#pragma once

#include <mutex>
#include <semaphore.h>
#include <deque>
#include <mysql.h>

class ConnPool
{
public:
	static ConnPool* getPool();

	void init(const std::string& host, const std::string& user, const std::string& pwd, const std::string& dbname, const int& port, const int& maxconn);
	MYSQL* getConn();
	bool releaseConn(MYSQL* conn);
private:
	ConnPool() { }
	void destroyPool();
	~ConnPool()
	{
		destroyPool();
	}
	std::deque<MYSQL*> connDeque;
	std::string host, user, pwd, dbname;
	int port, maxconn, curconn = 0, freecon = 0;
	sem_t sem;
	std::mutex mutex;
};