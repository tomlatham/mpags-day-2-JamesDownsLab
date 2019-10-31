#include "writeOutput.hpp"

#include <string>
#include <fstream>
#include <iostream>

void write_output(
        const std::string &outputFile,
        const std::string &outputText) {
    /*
     * Writes outputText to outputFile. If outputFile is an empty string
     * write the output to the console.
     */
    if (!outputFile.empty()) {
        std::ofstream out_file{outputFile};
        bool ok_to_write{out_file.good()};
        if (ok_to_write) {
            out_file << outputText;
        } else {
            std::cerr << "Error writing file" << std::endl;
        }
    } else {
        std::cout << outputText << std::endl;
    }
}
