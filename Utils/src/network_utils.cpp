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
#include <vector>

std::vector<std::string> resolve_hostname(const std::vector<std::string> &hostnames)
{
    std::vector<std::string> resolve_hostnames;
    addrinfo hints;
    addrinfo *result, *rp;

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;
    for (size_t i = 0; i < hostnames.size(); i++)
    {

        int res = getaddrinfo(hostnames[i].c_str(), NULL, &hints, &result);
        if (res != 0)
        {
            std::cerr << "Can't get address ip info\n";
            return {};
        }

        for (rp = result; rp != NULL; rp = rp->ai_next)
        {
            resolve_hostnames.push_back(inet_ntoa(((sockaddr_in *)rp->ai_addr)->sin_addr));
        }
        freeaddrinfo(result);
    }

    return resolve_hostnames;
}