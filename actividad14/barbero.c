#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define APP_PORT 6235
#define APP_HOST "127.0.0.1"
#define APP_BUFFER 1024 // bytes

#define BAR_SILLAS 3
#define MENU "PRESIONA Q PARA SALIR\n"

void die(char* msg){

	perror(msg);
	exit(1);
}

int main(int* argc, char** argv){

	printf("starting server el barbero \n");
	

	int res, sfd = -1;
	sfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sfd <= -1 ){
		die("error creating the socket");
	}

	struct sockaddr_in local;
	
	memset( (char*) &local, 0, sizeof(struct sockaddr));

	local.sin_port = htons(APP_PORT);
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = htonl(INADDR_ANY);

	res = bind(sfd, (struct sockaddr*) &local, sizeof(local));

	if (sfd <= -1 ){
		die("error binding the socket ");
	}

	char buffer[APP_BUFFER];

	printf("numero de sillas %i \n", BAR_SILLAS);
	printf( "%s", MENU);



	while(1){


	}

	return 0;
}
