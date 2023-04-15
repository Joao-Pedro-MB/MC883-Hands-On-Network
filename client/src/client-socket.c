/*
** client.c -- a stream socket client demo
*/

#include "client-socket.h"

void initialize_socket(int * sockfd, struct addrinfo * hints, struct addrinfo * servinfo, struct addrinfo * p, int * rv, s) {
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((*rv = getaddrinfo(IP, PORT, hints, servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {

        if ((*sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(*sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(*sockfd);
            perror("client: connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr), s, sizeof s);
    printf("client: connecting to %s\n", s);
    freeaddrinfo(servinfo); // all done with this structure
}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int use_socket(char * request) {
	
    int sockfd, bytes_received;
    char response[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    initialize_socket(sockfd, &hints, servinfo, p, $rv, s);

    if (send(sockfd, request, strlen(request), 0) == -1)
        perror("send");

    if ((bytes_received = recv(sockfd, response, MAXDATASIZE - 1, 0)) == -1) {
        perror("recv");
        exit(1);
    }

    response[bytes_received] = '\0';



    close(sockfd);

    return response;
}