/*
 * Misc. functions for printing.
 */

#include <string>

void print_status(std::string message);
void print_error(std::string message);
void print_good(std::string message);
void failure(int exit_code, std::string message);
