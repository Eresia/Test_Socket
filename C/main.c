#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "server.h"
#include "client.h"

char* help();

int main(int argc, char** argv){
	if(argc < 3){
		printf("%s\n", help());
		return -1;
	}

	if(strcmp(argv[1], "-c") == 0){
		if(argc < 4){
			printf("%s\n", help());
			return -3;
		}

		char* ip = argv[2];
		int port = atoi(argv[3]);

		if(port == 0){
			printf("Port have to be a number > 0");
			return -4;
		}

		return connectToUDPServer(ip, port);
	}
	else if(strcmp(argv[1], "-s") == 0){
		int port = atoi(argv[2]);

		if(port == 0){
			printf("Port have to be a number > 0");
			return -5;
		}

		return createUDPServer(port);
	}
	else{
		printf("%s\n", help());
		return -2;
	}
}

char* help(){
	return "Usage : \ncreateUDP.out [-c ip port] [-s port]\n-c : Create client\n-s : Create Server";
}
