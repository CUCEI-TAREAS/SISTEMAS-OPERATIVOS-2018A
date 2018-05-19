#include "base.h"

void exit_msg(char* msg){

	perror(msg);
	exit(1);
}

void *wait_exit( void* ptr );

int main(int* argc, char** argv){

	printf("starting server el barbero \n");

	int res, sfd = -1;

	char buffer[APP_BUFFER];
	memset(buffer, 0, APP_BUFFER);
	memset(buffer, hola_server, 4);

	sfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sfd <= -1 ){
		exit_msg("error creating the socket");
	}

	struct sockaddr_in server;
	
	memset( (char*) &server, 0, sizeof(struct sockaddr));

	server.sin_port = htons(APP_PORT);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	size_t respuesta = sendto(sfd, buffer, 40, 0, (struct sockaddr*) &server, sizeof(struct sockaddr));


	return 0;
}
