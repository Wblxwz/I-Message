#ifndef SERVER_H

#define SERVER_H

#include <vector>
#include "sqloperate.h"

void deleteFromCfds(const int& cfd);
void addMap(const int& cfd, const char* s);
const char* getAccount(const int& cfd);
void addInfos(std::vector<info*> info);

#endif // !SERVER_H

