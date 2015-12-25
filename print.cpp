/*
 * Common printing functions to use in client/server.
 */

#include <cstdlib>
#include <iostream>

void print_status(std::string message)
{
    std::cout << "\033[36m[*]\033[0m " << message << std::endl;
}

void print_error(std::string message)
{
    std::cout << "\033[31m[-]\033[0m " << message << std::endl;
}

void print_good(std::string message)
{
    std::cout << "\033[32m[+]\033[0m " << message << std::endl;
}

void failure(int exit_code, std::string message)
{
    std::cout << "\033[31m[!]\033[0m " << message << std::endl;
    exit(exit_code);
}
