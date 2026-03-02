#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(){

    // Creating a socket
    int socketfd = socket(AF_INET,SOCK_STREAM,0);

    // Structure for Client Address
    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(9002);
    client_address.sin_addr.s_addr = INADDR_ANY;

    // Binding the Socket
    int bind_status = bind(socketfd, (struct sockaddr *)&client_address, sizeof(client_address));

    // Listening the Socket
    int listen_status = listen(socketfd,5);

    // Accept
    int client_socket;
    client_socket = accept(socketfd,NULL,NULL);

    // Sending message
    char message[1000] = "You have reached the server!\n";
    send(client_socket,message,sizeof(message),0);

    // Close the socket
    close(socketfd);





}