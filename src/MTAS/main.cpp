#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

int main() {
    
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr{}, clientAddr{};
    socklen_t clientAddrSize;

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Set up the server address struct
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(587); // Port number, change as needed
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Use any available IP address

    // Bind the socket to the specified port
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error binding socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 10) == -1) {
        std::cerr << "Error listening on socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "Server listening on port 8080..." << std::endl;

    // Accept incoming connection
    clientAddrSize = sizeof(clientAddr);
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket == -1) {
         std::cerr << "Error accepting connection" << std::endl;
         close(serverSocket);
         return 1;
    }

    std::cout << "Connection accepted" << std::endl;
    // Print client IP address
    char clientIp[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddr.sin_addr, clientIp, INET_ADDRSTRLEN);
    std::cout << "Client IP: " << clientIp << std::endl;
    
    
    // Handle the connection, e.g., receive/send data

    
    // send a message to the client
    char message[] = "Hello, client!\n";
    send(clientSocket, message, sizeof(message), 0);
    
//     receive a message from the client
    char buffer[1024] = {0};
    printf("Waiting for client message...\n");
    recv(clientSocket, buffer, 1024, 0);
    printf("Client message: %s\n", buffer);

    // Close sockets
     close(clientSocket);
     close(serverSocket);
    return 0;
}
