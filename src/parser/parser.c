#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct req_fields parse_request(const char request[MAX_REQ_SIZE]){
	struct req_fields fields;
	char *req_copy, *line, *token;

	// Duplicate to avoid modifying the original request
	req_copy = strdup(request);

	// Extract first line of the request
	line = strtok(req_copy, "\n");
	
	// Extract method
	token = strtok(line, " ");
	if (strcmp(token, "GET") == 0)
		fields.method = GET;

	// TODO: extract PATH, version and host

	return fields;
}
