//I pledge My honor that I have abided by the Stevens Honor System -Bsoong
#include "cs392_log.h"

#define MAXPENDING 5
#define BUFFSIZE 1024

int main (int argc, char * argv[]){
	int clientSocket;
  int serverSocket;
  char buffer[BUFFSIZE];
	struct sockaddr_in echoserver;
  struct sockaddr_in echoclient;

	if(argc != 2) {
		printf("Error: Need only one argument \n");
		exit(EXIT_FAILURE);
	}
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1){
		printf("Error: Cannot create Socket \n");
		exit(1);
	}
	memset(&echoserver, 0, sizeof(echoserver));

  //Echoserver uses Internet/Ip
	echoserver.sin_family = AF_INET;
  //using Ip addresses
	echoserver.sin_addr.s_addr = htonl(INADDR_ANY);
  //uses server port
	echoserver.sin_port = htons(atoi(argv[1]));

  //If statement to check if it binds
	if (bind(serverSocket, (struct sockaddr *) &echoserver, sizeof(echoserver)) != 0) {
		printf("Error: Cannot bind the socket \n");
		exit(1);
	}

	//If statement used to check for client
	if (listen(serverSocket, MAXPENDING) != 0){
		printf("Error: Cannot find echoClient \n");
		exit(1);
	}
	//Run Forever until external input exits
	while (1) {
		socklen_t clientLength = sizeof(echoclient);
		clientSocket = accept(serverSocket, (struct sockaddr *) &echoclient, &clientLength);
		cs392_SocketLogger(echoclient.sin_addr.s_addr, echoclient.sin_port);

    //Another buffer reset
		memset(&buffer, '\0', sizeof(buffer));
    //recV Recieves client
		recv(clientSocket, buffer, BUFFSIZE, 0);
    //send sends message back to the client
		send(clientSocket, buffer, BUFFSIZE, 0);
    //close ends client connection
		close(clientSocket);
	}
	close(serverSocket);
	exit(1);
}
