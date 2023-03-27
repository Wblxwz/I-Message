#include <mysql/mysql.h>
#include <assert.h>
#include <iostream>

#include "connpool.h"

ConnPool* ConnPool::getPool()
{
	static ConnPool pool;
	return &pool;
}

void ConnPool::init(const std::string& host, const std::string& user, const std::string& pwd, const std::string& dbname, const int& port, const int& maxconn)
{
	this->host = host;
	this->user = user;
	this->pwd = pwd;
	this->dbname = dbname;
	this->port = port;

	for (int i = 0; i < maxconn; ++i)
	{
		MYSQL* conn = nullptr;
		conn = mysql_init(conn);
		assert(conn);
		conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pwd.c_str(), dbname.c_str(), port, NULL, 0);
		assert(conn);
		connDeque.push_back(conn);
		++freecon;
	}

	this->maxconn = maxconn;
	sem_init(&sem, 0, freecon);
}

MYSQL* ConnPool::getConn()
{
	if (connDeque.empty())
		return nullptr;
	sem_wait(&sem);
	std::lock_guard<std::mutex> locker(mutex);
	MYSQL* conn = connDeque.front();
	connDeque.pop_front();
	--freecon;
	++curconn;
	std::cout << "getConnection" << std::endl;
	return conn;
}

bool ConnPool::releaseConn(MYSQL* conn)
{
	if (!conn)
		return false;
	std::lock_guard<std::mutex> locker(mutex);
	connDeque.push_back(conn);
	++freecon;
	--curconn;
	sem_post(&sem);
	std::cout << "releaseConnection" << std::endl;
	return true;
}

void ConnPool::destroyPool()
{
	std::lock_guard<std::mutex> locker(mutex);
	if (!connDeque.empty())
	{
		for (auto& conn : connDeque)
			mysql_close(conn);
		curconn = 0;
		freecon = 0;
		connDeque.clear();
	}
	sem_destroy(&sem);
}
