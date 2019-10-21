// Standard Library includes
#include <iostream>
#include <string>
#include <vector>


// Our project headers
#include "processCommandLine.hpp"
#include "readInput.hpp"
#include "writeOutput.hpp"
#include "CaesarCipher.hpp"


// Main function of the mpags-cipher program
int main(int argc, char *argv[]) {
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{};
    std::string outputFile{};
    int defaultKey{5};
    bool encrypt{true};

    bool commandLineFailed{true};

    commandLineFailed = processCommandLine(
            cmdLineArgs,
            helpRequested,
            versionRequested,
            inputFile,
            outputFile,
            defaultKey,
            encrypt
    );

    if (commandLineFailed) {
        return 1;
    }

    // Handle help, if requested
    if (helpRequested) {
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
                << "                   Stdout will be used if not supplied\n\n";
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Read the input, from a file if given, from console otherwise
    std::string inputText{read_input(inputFile)};

    std::string outputText{runCaesarCipher(inputText, true)};

    // Output the transliterated text.
    // To output file if given, to screen if not.
    write_output(outputFile, inputText);

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}

