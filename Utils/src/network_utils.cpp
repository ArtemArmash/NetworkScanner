#include "network_utils.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

void resolve_hostname(const char *hostname)
{
    addrinfo hints;
    addrinfo *result, *rp;

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family =AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=0;
    hints.ai_protocol=0;

    int res = getaddrinfo(hostname, NULL, &hints, &result);
    if(res!=0){
        throw(gai_strerror(res));
        exit(EXIT_FAILURE);
    }

    for(rp = result; rp != NULL; rp=rp->ai_next){
        std::cout << inet_ntoa(((sockaddr_in*)rp->ai_addr)->sin_addr) << std::endl;
    }
    if(rp==NULL){
        exit(EXIT_FAILURE);
    }
}