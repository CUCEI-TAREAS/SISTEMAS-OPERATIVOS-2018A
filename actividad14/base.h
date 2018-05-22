#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<semaphore.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>

#define APP_PORT 6235
#define APP_HOST "127.0.0.1"
#define APP_BUFFER 12 // bytes

#define BAR_SILLAS 3
#define KEY_EXIT "q"
#define CLEAR_SCREEN system("clear")
#define MENU "PRESIONA " KEY_EXIT " PARA SALIR\n"

//network protocol
enum protocol_server { hola_cliente, no_hay_lugar, toma_asiento };
enum protocol_client { hola_server='a', gracias, tomo_asiento };

void exit_msg(char* msg){

	perror(msg);
	exit(1);
}
