#include "processCommandLine.hpp"

#include <iostream>
#include <string>
#include <vector>

bool processCommandLine (
  const std::vector<std::string>& cmdLineArgs,
  bool& helpRequested,
  bool& versionRequested,
  std::string& inputFile,
  std::string& outputFile,
  std::size_t& defaultKey,
  bool& encrypt
)
{
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  // assuming encryption by default (unless --decrypt is encountered),
  // so explicitly set it to true before processing the args
  encrypt = true;

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
        return true;
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
        return true;
      }
      else {
        outputFile = cmdLineArgs[i+1];
        ++i;
      }
    }
    else if (cmdLineArgs[i] == "-k") {
      // Handle default key
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -k requires a default key size" << std::endl;
        // exit with non-zero
        return true;
      }
      else {
        defaultKey = std::stoul(cmdLineArgs[i+1]);
        ++i;
      }
    }
    else if (cmdLineArgs[i] == "--decrypt") {
      encrypt = false;
    }
    else {
      // Have an unknown flag to output error message
      std::cerr << "[error] unknown argument '" << cmdLineArgs[i] << "'\n";
      // Exit with non-zero
      return true;
    }
  }
  return false;
}
