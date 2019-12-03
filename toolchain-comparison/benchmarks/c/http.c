#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    struct addrinfo hints, *res;
    int sockfd;

    char buf[2056];
    int byte_count;

    memset(&hints, 0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    getaddrinfo("www.uzh.ch","80", &hints, &res);
    sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    connect(sockfd,res->ai_addr,res->ai_addrlen);
    char *header = "GET /index.html HTTP/1.1\r\nHost: www.uzh.ch\r\n\r\n";
    send(sockfd,header,strlen(header),0);
    byte_count = recv(sockfd,buf,sizeof(buf),0);
    printf("%d bytes received\n",byte_count);
    printf("%.*s",byte_count,buf); 
    close(sockfd);
    return 0;
}