#include <asm-generic/socket.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>  // For sockaddr_in (IPv4)
#include <arpa/inet.h>   // For inet_pton(), etc.
#include <unistd.h>      // For close()
#include <sys/wait.h>


/*
 * SERVER part
 * */
int main(void)
{
	int srvfd, clifd;
	struct sockaddr_in srvaddr, cliaddr;
	socklen_t cliaddr_len;
	char cli_res[1024];
	
	// socket(file) descriptor for the server listener socket 
	srvfd = socket(AF_INET, SOCK_STREAM, 0);

	// set the server address values
	srvaddr.sin_family = AF_INET; // to indicate it is an ipv4 address
	srvaddr.sin_addr.s_addr = INADDR_ANY; // to listen to connections on any valid ip address in the machine
	srvaddr.sin_port = htons(8080); // port number in big endian
	

	// specify options to reuse the server address, bypassing the TIME_WAIT socket state.
	int opt = 1;
	setsockopt(srvfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	// bind the socket(file) descriptor to the address(+ port)
	if(bind(srvfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr))){
		perror("Could not bind socket");
		return EXIT_FAILURE;
	}
	

	// Listen for connections. Non-blocking. Enqueues the clients.
	if(listen(srvfd, 1) < 0){
		perror("Could not prepare socket for listening");
		return EXIT_FAILURE;
	}

	// creates a new socket clifd for communication with a client connected on srvfd, then sets cliaddr to the
	// client's address and its length.
	clifd = accept(srvfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
	if (clifd < 0){
		perror("Could not accept incomming connection from client");
		return EXIT_FAILURE;
	}

	send(clifd, "Hello from server", sizeof("Hello from server"), 0);
	recv(clifd, cli_res, sizeof(cli_res), 0);
	printf("%s\n", cli_res);

	close(clifd);

	close(srvfd);


	return EXIT_SUCCESS;
}
