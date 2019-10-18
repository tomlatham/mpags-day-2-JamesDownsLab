#include "writeOutput.hpp"

void write_output(std::string outputFile,
  std::string outputText){
    if (!outputFile.empty()) {
      std::ofstream out_file {outputFile};
      bool ok_to_write {out_file.good()};
    if (ok_to_write){
      out_file << outputText;
    }
    else{
        std::cerr << "Error writing file" << std::endl;
    }
  }
  else{
    std::cout << outputText << std::endl;
  }
}