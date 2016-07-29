#include "client.h"

int connectToUDPServer(char* ip, int port){

	int sock = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN to = { 0 };
	struct hostent *hostinfo = NULL;
	int tosize = sizeof to;

	char* buffer = malloc(100*sizeof(char));
	int n;
	int count = 0;

	if(sock == INVALID_SOCKET)
	{
	    return -6;
	}


	hostinfo = gethostbyname(ip);
	if (hostinfo == NULL)
	{
	    return -7;
	}

	to.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
	to.sin_port = htons(port);
	to.sin_family = AF_INET;

	while(1){
		sprintf(buffer, "%d", count);

		if(sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR *)&to, tosize) < 0)
		{
			return -8;
		}

		printf("Send : %s", buffer);

		if((n = recvfrom(sock, buffer, sizeof buffer - 1, 0, (SOCKADDR *)&to, (socklen_t*) &tosize)) < 0)
		{
			return -9;
		}

		buffer[n] = '\0';

		printf("Receive %s\n", buffer);

		count++;

		sleep(1);
	}

	return 0;
}
