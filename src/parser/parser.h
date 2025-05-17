#ifndef PARSER_H
#define PARSER_H

#define MAX_REQ_SIZE 4096

// Enum for all of the HTTP Methods
enum HTTPMethods {
	GET,
	POST,
	PUT,
	DELETE,
	PATCH,
	HEAD,
	OPTIONS,
	TRACE,
	CONNECT
};

// Structure holding information about the request
struct req_fields {
	int method;
	char *URI;
	float version;
	char host;
};

struct req_fields parse_request(const char request[MAX_REQ_SIZE]);

#endif // !PARSER_H


