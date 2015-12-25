/*
 * Minor socket abstraction
 */

#include "socket.hpp"

#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "print.hpp"

Socket::Socket(int sock, struct sockaddr_in address)
{
    _sock = sock;
    _address = address;
}

/*
 * Set up a socket as a listener.
 */
Socket::Socket(std::string host, std::string port)
{
    int size = sizeof(_address);
    memset(&_address, 0, size);
    _address.sin_family = AF_INET;
    _address.sin_port = htons(std::stoi(port));
    inet_pton(AF_INET, host.c_str(), &(_address.sin_addr));
    _sock = socket();
    if (_sock  < 0)
        failure(1, "socket()");
    if (bind() < 0)
        failure(1, "bind()");
    if (listen() < 0)
        failure(1, "listen()");
}

Socket::~Socket()
{
    shutdown(2);
    close();
}

int Socket::socket()
{
    //int sockval = ::socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //_sock = sockval;
    //return sockval;
    return ::socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
}

int Socket::bind()
{
    return ::bind(_sock, (struct sockaddr*)&_address, sizeof(_address));
}

int Socket::listen(int backlog)
{
    return ::listen(_sock, backlog);
}

int Socket::accept(struct sockaddr_in *client_address)
{
    socklen_t size = sizeof(*client_address);
    memset(client_address, 0, size);
    std::cout << "size: " << size << std::endl;
    std::cout << "sock: " << _sock << std::endl;
    int ret = ::accept(_sock, (sockaddr*)client_address, &size);
    std::cout << "ret :" << ret << std::endl;
    std::cout << "size:" << size << std::endl;
    return ret;
}

int Socket::send(std::string data)
{
    return ::send(_sock, data.c_str(), data.length(), 0);
}

std::string Socket::recv()
{
    char message[4096];
    int retval = ::recv(_sock, &message, 4096, 0);
    if (retval <= 0)
        std::cout << "recv() ERROR: " << retval << std::endl;
    return message;
}

void Socket::close()
{
    ::close(_sock);
}

void Socket::shutdown(int how)
{
    ::shutdown(_sock, how);
}

std::string Socket::addr()
{
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(_address.sin_addr), ip, INET_ADDRSTRLEN);
    return ip;
}

std::string Socket::port()
{
    return std::to_string(ntohs(_address.sin_port));
}
