#pragma once

#include <string>

#include "socket.hpp"

class ChatClient
{
public:
    ChatClient(int socket, struct sockaddr_in address);
    std::string address();
    int send(std::string message);
    std::string recv();

private:
    Socket socket;
};
