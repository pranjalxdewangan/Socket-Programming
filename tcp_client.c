#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h> // a system header file that defines important data types used by the operating system.
#include <netinet/in.h> // a network programming header used in Linux/Unix systems.



int main(){

    // Socket Descriptor for IPv4 TCP Connection
    int socketfd = socket(AF_INET,SOCK_STREAM,0);


    // Address where to connect -> struct sockaddr_in
    /*struct sockaddr_in {
           sa_family_t     sin_family;      // AF_INET 
           in_port_t       sin_port;        // Port number 
           struct in_addr  sin_addr;        // IPv4 address 
       };
       */
       struct sockaddr_in server_address;
       server_address.sin_family = AF_INET;
       server_address.sin_port = htons(9002);
       server_address.sin_addr.s_addr = INADDR_ANY;


       //Connect -> Client
       int connection_status = connect(socketfd,(struct sockaddr_in *)&server_address,sizeof(server_address));

       if(connection_status <= -1){
        printf("There is an error in connecting to the remote server...\n\n");
       }

       // Recieve Data from server
       char message[1000];
       recv(socketfd,message,sizeof(message),0);

       // Print out Server Response
       printf("SERVER: %s\n",message);

       // Closing the Socket
       close(socketfd);
        


    return 0;
}