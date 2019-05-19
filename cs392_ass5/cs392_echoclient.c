//I pledge my honor that I have abided by the Stevens Honor System -Bsoong
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAXPENDING 5
#define BUFFSIZE 36

int main(int argc, char * argv[]) {
  struct sockaddr_in echoserver;
  char buffer[BUFFSIZE];
  char input[BUFFSIZE];
	int clientSocket;
	unsigned int echoLength;
	int received = 0;
  if(argc != 3) {
    printf("Error: Need 2 arguments  \n");
    exit(EXIT_FAILURE);
  }

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket == -1) {
        	printf("Error: Cannot create socket \n");
        	exit(1);
    }

  //First memset resets the server, second memset resets input, and the third resets the buffer
	memset(&echoserver, 0, sizeof(echoserver));
	memset(&input, '\0', sizeof(input));
	memset(&buffer, '\0', sizeof(buffer));

  //Echos using Internet/Ip
	echoserver.sin_family = AF_INET;
  //Echos the IP address
	echoserver.sin_addr.s_addr = inet_addr(argv[1]);
  //Echo uses Server port
	echoserver.sin_port = htons(atoi(argv[2]));

  //check to see if it can connect
	if (connect(clientSocket, (struct sockaddr *) &echoserver, sizeof(echoserver)) != 0) {
		printf("Error: Cannot connect to the server\n");
	}

	printf("Enter a message to echo: ");
	fgets(input, sizeof(input), stdin);

	echoLength = strlen(input);
	send(clientSocket, input, echoLength, 0);
	recv(clientSocket, buffer, BUFFSIZE-1, 0);
	printf("%s\n", buffer);
	close(clientSocket);
	exit(1);
}
