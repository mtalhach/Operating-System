#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for client connections
    if (listen(sockfd, 1) == -1) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server is listening on port %d...\n", port);

    while (1) {
        // Accept a client connection
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int clientSocket = accept(sockfd, (struct sockaddr*)&clientAddress, &clientAddressLength);
        if (clientSocket == -1) {
            perror("Accepting connection failed");
            exit(1);
        }

        // Receive number from the client
        double number;
        read(clientSocket, &number, sizeof(double));
        printf("Received number %.6f from client\n", number);

        // Calculate square root
        double result = sqrt(number);

        // Send result back to the client
        write(clientSocket, &result, sizeof(double));
        printf("Sent square root %.6f to client\n", result);

        // Close the client socket
        close(clientSocket);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}

