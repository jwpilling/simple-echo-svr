#pragma once

#include <string>
#include "socket.hpp"

class ChatServer
{
public:
    ChatServer(std::string host, std::string port);
    int run();
    void handle_connection(int sock, struct sockaddr_in address);

private:
    Socket listener;
};
