#include "readInput.hpp"
#include "TransformChar.hpp"

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
        std::string typedText{};
        std::getline(std::cin, typedText);
        for (char i : typedText){
            inputText += transformChar(i);
        }
    }
    return inputText;
}