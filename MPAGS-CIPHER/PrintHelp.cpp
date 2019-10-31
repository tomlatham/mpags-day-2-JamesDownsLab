#include "PrintHelp.hpp"

#include <iostream>

void printHelp(){
    // Line splitting for readability
    std::cout
            << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -k KEY           Specify the cipher KEY (defaults to 5)\n\n"
            << "  --decrypt        Changes to decryption (defaults to encryption)\n"
            << std::endl;
    // Help requires no further action, so return from main
    // with 0 used to indicate success
}
