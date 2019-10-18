// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// For std::isalpha and std::isupper
#include <cctype>

// Our project headers
#include "TransformChar.hpp"
#include "processCommandLine.hpp"


// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  bool commandLineFailed{true};

  commandLineFailed = processCommandLine(
    cmdLineArgs,
    helpRequested,
    versionRequested,
    inputFile,
    outputFile
  );

  if (commandLineFailed){
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

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  if (!inputFile.empty()) {
    std::ifstream in_file {inputFile};
    bool ok_to_read {in_file.good()};
    if (ok_to_read){
      while (in_file >> inputChar){
        // Loop over each character from the input file
        inputText += transformChar(inputChar);
      }
    }
    else{
      std::cerr << "Error reading File" << std::endl;
    }
  }
  else{
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
    }
  }
  
  // Output the transliterated text.
  // To output file if given, to screen if not.
  if (!outputFile.empty()) {
    std::ofstream out_file {outputFile};
    bool ok_to_write {out_file.good()};
    if (ok_to_write){
      out_file << inputText;
    }
  }
  else{
    std::cout << inputText << std::endl;
  }

  

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}

