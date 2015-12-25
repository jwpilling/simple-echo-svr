/*
 * Starts the server.
 */

#include <iostream>

#include "server.hpp"

int main(const int argc, const char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <host> <port number>"
                  << std::endl;
        return 1;
    }

    ChatServer server(argv[1], argv[2]);
    return server.run();
}
