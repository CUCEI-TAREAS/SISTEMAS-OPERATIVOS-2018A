#include <pthread.h>
#include <signal.h>
#include "base.h"

// BARBERO GLOBAL VARIABLES // MUTEX
enum barberoStatus { durmiendo, trabajando };
int res, sfd = -1;
char buffer[APP_BUFFER];
pthread_t thread_receive, thread_scan;
sem_t len;

struct timespec ts;
struct sigaction sa;

char action[1];

	struct sockaddr* client;
	socklen_t* client_t;

// BARBERO FUNCTIONS
void *waitingClient( void* ptr );
void *readingInput( void* ptr );
void control();

int main(int* argc, char** argv){

	CLEAR_SCREEN;
	printf("starting server el barbero \n");

	sfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sfd <= -1 ){
		exit_msg("error creating the socket");
	}

	struct sockaddr_in addr;
	
	memset( (char*) &addr, 0, sizeof(struct sockaddr_in));

	addr.sin_port = htons(APP_PORT);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	res = bind(sfd, (struct sockaddr*) &addr, sizeof(addr));

	if (sfd <= -1 ){
		exit_msg("error binding the socket ");
	}

	printf("numero de sillas %i \n", BAR_SILLAS);

	memset((char*) &client, 0, sizeof(struct sockaddr));
	memset(&client_t, 0, sizeof(socklen_t));

	printf( "%s", MENU);
	sem_init(&len, 0, 0);

	sa.sa_handler = control;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	// waiting for clients
	pthread_create(&thread_scan, NULL, readingInput, NULL); 
	pthread_create(&thread_receive, NULL, waitingClient, NULL); 

	pthread_join(thread_scan, NULL);
	return 0;
}

void control(){
	static int f;
	printf("action %i", ++f);
}

// dormir
// terminar
// atender siguiente
//  en  espera
// sillas disponibles
// rechazados 
//

void *waitingClient( void* ptr){
	while(1){

	alarm(1);
	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_sec += 1;

		sem_timedwait(&len, &ts);
		int res_recv = recvfrom(sfd, buffer, APP_BUFFER, 0, client, client_t);

		printf("%i", res_recv);
		printf("%c", buffer);
	
	}
}

void *readingInput( void* ptr){

		//CLEAR_SCREEN;

	while(1){

		scanf("%s", &action);
		sem_post(&len);
		if( strcmp (action, KEY_EXIT ) == 0 ){
			exit(0);
		}
	}
}
