#pragma once

#include <mysql.h>

#include "connpool.h"

class ConnRAII
{
public:
	ConnRAII(ConnPool* pool, MYSQL** con) :pool(pool)
	{
		*con = pool->getConn();
		conn = *con;
	}
	~ConnRAII()
	{
		pool->releaseConn(conn);
	}
private:
	ConnPool* pool;
	MYSQL* conn;
};