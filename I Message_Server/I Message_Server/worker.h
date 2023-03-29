#ifndef WORKER_H

#define WORKER_H

class Worker
{
public:
	Worker(const int& cfd) :cfd(cfd) 
	{
	}
	void work();
	void signUp(const std::string& s, char* name, char* pwd);
	bool logIn(const std::string& s, char* account, char* pwd);
	~Worker();
private:
	int cfd;
};

#endif//WORKER_H