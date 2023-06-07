#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    int serverPort = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    if (inet_pton(AF_INET, argv[1], &(serverAddress.sin_addr)) <= 0) {
        perror("Invalid server IP address");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    // Send number to the server
    double number;
    printf("Enter a number: ");
    scanf("%lf", &number);
    write(sockfd, &number, sizeof(double));

    // Receive result from the server
    double result;
    read(sockfd, &result, sizeof(double));
    printf("Square root of %.6f is %.6f\n", number, result);

    // Close the socket
    close(sockfd);

    return 0;
}

