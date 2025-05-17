#ifndef SOCKET_H
#define SOCKET_H

/*
 * Creates and binds an IP socket to INADDR_ANY and the specified port. Returns the socket descriptor.
 * */
int ipsock(struct sockaddr_in address);

#endif // SOCKET_H
