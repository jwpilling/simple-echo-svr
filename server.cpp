/*
 * server class for Chatserver
 */

#include "server.hpp"

#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "client.hpp"
#include "socket.hpp"
#include "print.hpp"

ChatServer::ChatServer(std::string host, std::string port)
    : listener(Socket(host, port))
{
    print_status("Initializing server...");
}

int ChatServer::run()
{
    print_status("Listening on " + listener.addr() + ":" + listener.port());
    struct sockaddr_in client_address;
    int new_connection = 0;
    while ((new_connection = listener.accept(&client_address)))
    {
        if (new_connection < 0)
        {
            perror("Fail:");
            failure(1, "new_connection");
        }
        pid_t pid = fork();
        if (pid == 0)
        {
            handle_connection(new_connection, client_address);
            exit(0);
        }
        else if (pid > 0)
        {
            print_status("New client forked pid: " + std::to_string(pid));
            close(new_connection);
        }
    }
    print_status("Shutting down.");
    return 0;
}

void ChatServer::handle_connection(int socket, struct sockaddr_in address)
{
    listener.close();  // Child does not need listener.
    ChatClient client(socket, address);
    print_status("New client on " + client.address());
    while (true)
    {
        client.send(client.recv());
    }
}
