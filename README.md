# Socket-Programming
Basic TCP Socket Programming in C demonstrating client–server communication using IPv4 sockets. The server listens for incoming connections and sends a message to the client.


# TCP Socket Programming in C

This project demonstrates a simple Client–Server communication model using **TCP sockets in C** on Linux/Unix systems.
The server listens on a specific port and sends a message when a client connects. The client connects to the server and receives the message.
This project is useful for beginners learning:
- Socket Programming
- TCP Communication
- Client–Server Architecture
- Network Programming in C


# How It Works

### Server
1. Creates a TCP socket
2. Binds the socket to **port 9002**
3. Listens for incoming connections
4. Accepts a client connection
5. Sends a message to the client
6. Closes the socket

### Client
1. Creates a TCP socket
2. Connects to the server at **port 9002**
3. Receives the message sent by the server
4. Prints the message
5. Closes the socket

# Running 
# Compile both programs
gcc tcp_server.c -o server
gcc tcp_client.c -o client

# Run the server
./server

# Open another terminal and run the client
./client
