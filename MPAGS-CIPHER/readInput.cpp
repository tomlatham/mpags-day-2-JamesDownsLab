#include "readInput.hpp"
#include "TransformChar.hpp"

#include <string>
#include <fstream>
#include <iostream>

std::string read_input(
        const std::string &inputFile) {
    char inputChar{'x'};
    std::string inputText{};

    if (!inputFile.empty()) {
        std::ifstream in_file{inputFile};
        bool ok_to_read{in_file.good()};
        if (ok_to_read) {
            while (in_file >> inputChar) {
                // Loop over each character from the input file
                inputText += transformChar(inputChar);
            }
        } else {
            std::cerr << "Error reading File" << std::endl;
        }
    } else {
        while (std::cin >> inputChar) {
            inputText += transformChar(inputChar);
        }
    }
    return inputText;
}
