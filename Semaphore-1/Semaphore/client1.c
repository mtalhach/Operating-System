#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    short s;
    int sockfd, portno, n, term_con = 0;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if(argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);

    if(server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server -> h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Error connecting");

    while(1)
    {
        printf("Enter a short int: ");
        scanf("%hi", &s);
        
        n = write(sockfd, &s, sizeof(short));
        if(n < 0)
            error("ERROR writing to socket");
        if(s == -99)
        {
            close(sockfd);
            return 0;
        }
        n = read(sockfd, &s, sizeof(short));
        
        if (n < 0)
            error("ERROR writing to socket");
        printf("The Server sent: %hi\n", s);
    }
    
}
