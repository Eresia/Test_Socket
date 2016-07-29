#include "server.h"

int createUDPServer(int port){

	int sock = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN sin = { 0 };
	SOCKADDR_IN from = { 0 };
	int fromsize = sizeof from;

	char* buffer = malloc(100*sizeof(char));
	int n;

	if(sock == INVALID_SOCKET)
	{
	    return -6;
	}

	sin.sin_addr.s_addr = htonl(INADDR_ANY);

	sin.sin_family = AF_INET;

	sin.sin_port = htons(port);

	if(bind (sock, (SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR)
	{
	    return -7;
	}

	while(1){
		if((n = recvfrom(sock, buffer, sizeof buffer - 1, 0, (SOCKADDR *)&from, (socklen_t*) &fromsize)) < 0)
		{
		    return -8;
		}

		buffer[n] = '\0';

		printf ("Receive %s\n", buffer);

		if(sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR *)&from, fromsize) < 0)
		{
		    return -9;
		}

		printf("Send : %s", buffer);
	}


	return 0;
}
