#include <sys/socket.h>
#include <sys/epoll.h>
#include <assert.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "connpool.h"

#include "server.h"

void setNonBlock(const int& fd)
{
	int flag = fcntl(fd, F_GETFL);
	assert(flag >= 0);
	flag |= O_NONBLOCK;
	assert(fcntl(fd, F_SETFL, flag) >= 0);
}

void addFd(const int& epollfd, const int& fd, bool ONESHOT)
{
	epoll_event events;
	events.data.fd = fd;
	events.events = EPOLLIN | EPOLLET | EPOLLHUP;
	if (ONESHOT)
		events.events |= EPOLLONESHOT;
	setNonBlock(fd);
	assert(epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &events) != -1);
}

void signUp(const std::string& s)
{
	char name[16]{ '0' };
	char pwd[16]{ '0' };
	int n = s.find("pwd:");
	int x = 0;
	for (int i = 5; i < n; ++i)
		name[x++] = s[i];
	x = 0;
	n += 4;
	for (int i = n; i < s.size(); ++i)
		pwd[x++] = s[i];
}

void serverListen()
{
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(listenfd >= 0);
	sockaddr_in addr;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);

	int ret = bind(listenfd, (sockaddr*)&addr, sizeof(addr));
	assert(ret >= 0);

	ret = listen(listenfd, 5);
	assert(ret >= 0);

	int epollfd = epoll_create(5);
	assert(epollfd != -1);

	addFd(epollfd, listenfd, false);

	epoll_event eve[1000];
	while (true)
	{
		int num = epoll_wait(epollfd, eve, 1000, -1);
		if (num < 0 && errno != EINTR)
			break;
		for (int i = 0; i < num; ++i)
		{
			int fd = eve[i].data.fd;
			if (fd == listenfd)
			{
				sockaddr_in caddr;
				socklen_t tmplen = sizeof(caddr);
				while (true)
				{
					int connfd = accept(listenfd, (sockaddr*)&caddr, &tmplen);
					if (connfd < 0)
						break;
					addFd(epollfd, connfd, true);
				}
			}
			else if (eve[i].events & EPOLLIN)
			{
				int cfd = eve[i].data.fd;
				char buf[1024]{ '0' };
				recv(cfd, buf, sizeof(buf), NULL);

				std::string s(buf);
				if (s.find("name:") != -1)
					signUp(s);

				send(cfd, buf, strlen(buf), 0);
			}
		}
	}
	close(epollfd);
	close(listenfd);
}

int main(int argc, char* argv[])
{
	ConnPool* pool = ConnPool::getPool();
	pool->init("localhost", "root", "a2394559659", "imessage", 3306, 5);
	serverListen();
	return 0;
}