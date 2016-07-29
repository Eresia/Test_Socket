#include "client.h"

int connectToUDPServer(char* ip, int port){

	int sock = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN to = { 0 };
	struct hostent *hostinfo = NULL;
	int tosize = sizeof to;

	char* buffer = malloc(100*sizeof(char));
	int count = 0;
	pthread_t thread;
	Informations info;

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

	info.socket = sock;
	info.to = to;
	info.tosize = tosize;

	thread = pthread_create(&thread, NULL, receiveMsg, &info);

	while(1){
		sprintf(buffer, "%d", count);

		if(sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR *)&to, tosize) < 0)
		{
			return -8;
		}

		printf("Send : %s\n", buffer);

		count++;

		sleep(1);
	}

	pthread_join(thread, NULL);

	return 0;
}

void* receiveMsg(void* info){

	Informations* informations = (Informations*) info;
	int sock = informations->socket;
	SOCKADDR_IN to = informations->to;
	int tosize = informations->tosize;

	int n;
	char* buffer = calloc(100, sizeof(char));

	int* err = malloc(sizeof(int));
	*err = 0;

	while(1){
		if((n = recvfrom(sock, buffer, sizeof buffer - 1, 0, (SOCKADDR *)&to, (socklen_t*) &tosize)) < 0)
		{
			*err = -9;
			pthread_exit(err);
		}

		buffer[n] = '\0';

		printf("Receive %s\n\n", buffer);
	}

	pthread_exit(err);
}
