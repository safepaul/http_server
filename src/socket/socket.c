#include <stdio.h>
#include <netinet/in.h>

#include "socket.h"

// Create and bind an ip socket with address struct ADDRESS
int ipsock(struct sockaddr_in address){
	int fd  = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0){
		perror("Could not create socket");
		return -1;
	}

	// specify options to reuse the server address, bypassing the TIME_WAIT socket state.
	int opt = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	if(bind(fd, (struct sockaddr *)&address, sizeof(address)) < 0){
		perror("Could not bind socket");
		return -1;
	}

	return fd;
}
