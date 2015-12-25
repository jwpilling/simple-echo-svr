#pragma once

#include <string>
#include <netinet/in.h>

class Socket
{
public:
    Socket(int sock, struct sockaddr_in address);
    Socket(std::string host, std::string port);
    ~Socket();
    int socket();
    int bind();
    int listen(int backlog=10);
    int accept(struct sockaddr_in *client_address);
    int send(std::string data);
    std::string recv();
    void close();
    void shutdown(int how=2);
    std::string addr();
    std::string port();

private:
    int _sock;
    struct sockaddr_in _address;
};
