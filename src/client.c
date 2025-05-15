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


/*
 * SERVER part
 * */
int main(void)
{
	int clifd;
	struct sockaddr_in srvaddr;
	char srv_res[1024];


	clifd = socket(AF_INET, SOCK_STREAM, 0);

	srvaddr.sin_family = AF_INET;
	srvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	srvaddr.sin_port = htons(8080);
	puts("[CLIENT] Connecting to server");
	if(connect(clifd, (struct sockaddr *)&srvaddr, sizeof(srvaddr))){
		perror("Could not connect to server");
	}
	puts("[CLIENT] Sucessfully connected to server");

	recv(clifd, srv_res, sizeof(srv_res), 0);
	send(clifd, "Hello from client", sizeof("Hello from client"), 0);
	printf("%s", srv_res);
	
	close(clifd);


	return EXIT_SUCCESS;
}
