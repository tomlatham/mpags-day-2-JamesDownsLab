// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

std::string transformChar(const char in_char);

bool processCommandLine (
  const std::vector<std::string>& cmdLineArgs,
  bool& helpRequested,
  bool& versionRequested,
  std::string& inputFile,
  std::string& outputFile
);

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
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::cout << "[warning] input from file ('"
              << inputFile
              << "') not implemented yet, using stdin\n";
  }

  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
  while(std::cin >> inputChar)
  {
    inputText += transformChar(inputChar);;
  }

  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty()) {
    std::cout << "[warning] output to file ('"
              << outputFile
              << "') not implemented yet, using stdout\n";
  }

  std::cout << inputText << std::endl;

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}

bool processCommandLine (
  const std::vector<std::string>& cmdLineArgs,
  bool& helpRequested,
  bool& versionRequested,
  std::string& inputFile,
  std::string& outputFile
)
{
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  for (size_type i {1}; i < nCmdLineArgs; i++) {
    if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
      helpRequested = true;
    }
    else if (cmdLineArgs[i] == "--version") {
      versionRequested = true;
    }
    else if (cmdLineArgs[i] == "-i") {
      // Handle input file option
      // NExt element is filename unless -i is the last argument
      if (i == nCmdLineArgs -1) {
        std::cerr << "[error] -i requires a filename argument" << std::endl;
        // exit with non-zero
        return 1;
      }
      else {
        // Got filename, so assign value and advance past it
        inputFile = cmdLineArgs[i+1];
        ++i;
      }
    }
    else if (cmdLineArgs[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        // exit with non-zero
        return 1;
      }
      else {
        outputFile = cmdLineArgs[i+1];
        ++i;
      }
    }
    else {
      // Have an unknown flag to output error message
      std::cerr << "[error] unknown argument '" << cmdLineArgs[i] << "'\n";
      // Exit with non-zero
      return 1;
    }
  }
  return 0;
}

std::string transformChar(const char in_char){
  /* Transform the input characters to the required input.
  
  All letters are returned uppercase.
  All digits are returned as the uppercase spelling of their number.
  All other symbols are ignored.
  */

  // Uppercase alphabetic characters
  std::string out_string {""};

  if (std::isalpha(in_char)) {
    out_string = std::toupper(in_char);
  }
  else {
    // Transliterate digits to English words
    switch (in_char) {
      case '0':
        out_string = "ZERO";
        break;
      case '1':
        out_string = "ONE";
        break;
      case '2':
        out_string = "TWO";
        break;
      case '3':
        out_string = "THREE";
        break;
      case '4':
        out_string = "FOUR";
        break;
      case '5':
        out_string = "FIVE";
        break;
      case '6':
        out_string = "SIX";
        break;
      case '7':
        out_string = "SEVEN";
        break;
      case '8':
        out_string = "EIGHT";
        break;
      case '9': 
        out_string = "NINE";
        break;
      default:
        out_string = "";
        break;
    }
  }
  return out_string;
}