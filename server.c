#include "server.h"

int createUDPServer(int port){

	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock == INVALID_SOCKET)
	{
	    return -6;
	}


	return 0;
}
