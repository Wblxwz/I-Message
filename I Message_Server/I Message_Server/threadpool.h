#pragma once

#include <pthread.h>
#include <deque>
#include <mutex>
#include <semaphore.h>

#include "worker.h"

class ThreadPool
{
public:
	static ThreadPool* getThreadPool(const int& threadnum = 8, const int& maxrequestsnum = 10000);
	static void* worker(void* arg);
	void run();
	bool add(Worker* worker);
private:
	ThreadPool(const int& threadnum, const int& maxrequestsnum);
	~ThreadPool();

	int threadnum, maxrequestsnum;
	std::deque<Worker*> workDeque;
	std::mutex mutex;
	sem_t sem;
	pthread_t* threads;
};