#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>

#include "../parser/parser.h"
#include "../socket/socket.h"


int main(void)
{
	int srvfd, clifd;
	struct sockaddr_in srvaddr, cliaddr;
	socklen_t cliaddr_len;
	char request[MAX_REQ_SIZE];

	// Set the server address struct values
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_addr.s_addr = INADDR_ANY;
	srvaddr.sin_port = htons(8080);
	
	// Create and bind the socket to the specified address
	srvfd = ipsock(srvaddr);
	if(srvfd == -1){
		puts("Error calling function ipsock()");
		return EXIT_FAILURE;
	}

	// Listen for connections
	if(listen(srvfd, 1) == -1){
		perror("Could not prepare socket for listening");
		return EXIT_FAILURE;
	}

	// Creates a new socket for communication with ONE client that requested connection to the server socket
	clifd = accept(srvfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
	if (clifd == -1){
		perror("Could not accept incomming connection from client");
		return EXIT_FAILURE;
	}

	// Receive HTTP request in REQUEST buffer
	recv(clifd, request, sizeof(request), 0);

	// TODO: Handle the request here



	// Once finished communicating with client, close socket to avoid resource starvation
	close(clifd);

	// Once server stops communication, close server open socket
	close(srvfd);

	return EXIT_SUCCESS;
}
