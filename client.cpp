#include "client.hpp"

ChatClient::ChatClient(int sock, struct sockaddr_in address)
    : socket(sock, address)
{
}

std::string ChatClient::address()
{
    return socket.addr() + ":" + socket.port();
}

int ChatClient::send(std::string message)
{
    return socket.send(message);
}

std::string ChatClient::recv()
{
    return socket.recv();
}
