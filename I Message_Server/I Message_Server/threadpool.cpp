#include <assert.h>

#include "threadpool.h"

void ThreadPool::run()
{
	while (true)
	{
		sem_wait(&sem);
		std::unique_lock<std::mutex> locker(mutex);

		if (workDeque.empty())
		{
			locker.unlock();
			continue;
		}

		Worker* request = workDeque.front();
		workDeque.pop_front();
		locker.unlock();

		if (!request)
			continue;

		request->work();
	}
}

void* ThreadPool::worker(void* arg)
{
	ThreadPool* pool = (ThreadPool*)arg;
	pool->run();
	return pool;
}

ThreadPool::ThreadPool(const int& threadnum, const int& maxrequestsnum)
{
	sem_init(&sem, 0, 0);
	assert(threadnum > 0 && maxrequestsnum > 0);
	threads = new pthread_t[threadnum];
	assert(threads);
	for (int i = 0; i < threadnum; ++i)
	{
		if (pthread_create(threads + i, NULL, worker, this) != 0)
		{
			delete[] threads;
			abort();
		}
		if (pthread_detach(threads[i]) != 0)
		{
			delete[] threads;
			abort();
		}
	}
}

ThreadPool::~ThreadPool()
{
	std::lock_guard<std::mutex> locker(mutex);
	if (!workDeque.empty())
		for (auto& i : workDeque)
			delete i;
	sem_destroy(&sem);
	delete[] threads;
}

ThreadPool* ThreadPool::getThreadPool(const int& threadnum, const int& maxrequestsnum)
{
	static ThreadPool pool(threadnum, maxrequestsnum);
	return &pool;
}

bool ThreadPool::add(Worker* worker)
{
	std::unique_lock<std::mutex> locker(mutex);
	if (workDeque.size() > maxrequestsnum)
	{
		locker.unlock();
		return false;
	}
	workDeque.push_back(worker);
	sem_post(&sem);
	return true;
}
