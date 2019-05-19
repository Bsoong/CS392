//I pledge My honor that I have abided by the Stevens Honor System -Bsoong
#include "cs392_log.h"

void cs392_SocketLogger(int add, int port){
	FILE *file;
	file = fopen("cs392_socket.log", "a");
	if (file == NULL) {
    	printf("Error: Cannot Print the file.");
  }
	fprintf(file, "%d %d\r\n", add, port);
	fflush(file);
	fclose(file);
}
