#ifndef WORKER_H

#define WORKER_H

#include "sqloperate.h"
#include <vector>

class Worker
{
public:
	Worker(const int& cfd, std::vector<info*> infos) :cfd(cfd),infos(infos)
	{
	}
	void work();
	void signUp(const std::string& s, char* name, char* pwd);
	bool logIn(const std::string& s, char* account, char* pwd);
	~Worker();
private:
	int cfd;
	std::vector<info*> infos;
};

#endif//WORKER_H