#include "base.h"

// definir el protocolo de msg
// create a client
// recibir a cliente 
//
void exit_msg(char* msg){

	perror(msg);
	exit(1);
}

void *wait_exit( void* ptr );

int main(int* argc, char** argv){

	printf("starting server el barbero \n");

	int res, sfd = -1;
	sfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sfd <= -1 ){
		exit_msg("error creating the socket");
	}

	struct sockaddr_in local;
	
	memset( (char*) &local, 0, sizeof(struct sockaddr));

	local.sin_port = htons(APP_PORT);
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = htonl(INADDR_ANY);

	res = bind(sfd, (struct sockaddr*) &local, sizeof(local));

	if (sfd <= -1 ){
		exit_msg("error binding the socket ");
	}

	char buffer[APP_BUFFER];

	printf("numero de sillas %i \n", BAR_SILLAS);
	printf( "%s", MENU);

	struct sockaddr* client = NULL;
	socklen_t* client_t = NULL; 

	recvfrom(sfd, buffer, APP_BUFFER, 0, client, client_t);
	printf("%s", buffer);


	return 0;
}
