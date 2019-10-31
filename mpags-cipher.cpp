// Standard Library includes
#include <iostream>
#include <string>
#include <vector>


// Our project headers
#include "processCommandLine.hpp"
#include "readInput.hpp"
#include "writeOutput.hpp"
#include "CaesarCipher.hpp"
#include "PrintHelp.hpp"


// Main function of the mpags-cipher program
int main(int argc, char *argv[]) {
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{};
    std::string outputFile{};
    std::size_t key{5};
    bool encrypt{true};

    bool commandLineFailed { processCommandLine(
            cmdLineArgs,
            helpRequested,
            versionRequested,
            inputFile,
            outputFile,
            key,
            encrypt
    ) };

    if (commandLineFailed) {
        return 1;
    }

    // Handle help, if requested
    if (helpRequested) {
        printHelp();
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.2.0" << std::endl;
        return 0;
    }

    // Read the input, from a file if given, from console otherwise
    std::string inputText{read_input(inputFile)};

    std::string outputText{runCaesarCipher(inputText, encrypt, key)};

    // Output the transliterated text.
    // To output file if given, to screen if not.
    write_output(outputFile, outputText);

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}

