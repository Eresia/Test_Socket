#ifndef CLIENT
#define CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "network.h"

typedef struct Informations Informations;
struct Informations{
	int socket;
	SOCKADDR_IN to;
	int tosize;
};

int connectToUDPServer(char* ip, int port);
void* receiveMsg(void* info);

#endif
