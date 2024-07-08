#include "erproc.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

void ErrorPrint(const int res, const char *msg, int error_code){
    if(res == error_code){
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

int Socket(int domain, int type, int protocol){
	int res = socket(domain, type, protocol);

    ErrorPrint(res, "socket failed", -1);

	return res;
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int res = bind(sockfd, addr, addrlen);

    ErrorPrint(res, "bind failed", -1);
}

void Listen(int sockfd, int backlog){
    int res = listen(sockfd, backlog);

    ErrorPrint(res, "listen failed", -1);
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    int res = accept(sockfd, addr, addrlen);

    ErrorPrint(res, "accept failed", -1);

    return res;
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int res = connect(sockfd, addr, addrlen);

    ErrorPrint(res, "connect failed", -1);
}

void Inet_pton(int af, const char *src, void *dst){
    int res = inet_pton(af, src, dst);

    ErrorPrint(res, "inet_pton failed: src does not contain a character\n", 0);

    ErrorPrint(res, "inet_pton failed", -1);
}
