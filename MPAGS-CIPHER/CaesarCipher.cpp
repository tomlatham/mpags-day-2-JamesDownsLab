#include "CaesarCipher.hpp"

std::string runCaesarCipher(
        const std::string& inputText,
        const bool& encrypt,
        const std::size_t& key){

    std::string outputText;

    const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::string::size_type alphabetSize{alphabet.size()};

    const std::size_t truncatedKey { key % alphabetSize };

    for (char i : inputText){
        for (std::size_t pos{0}; pos < alphabetSize; ++pos){
            if (alphabet[pos]==i){
                if (encrypt){
                    outputText += alphabet[(pos + truncatedKey)%alphabetSize];
                } else{
                    outputText += alphabet[(alphabetSize + pos - truncatedKey)%alphabetSize];
                }
                break;
            }
        }
    }
    return outputText;
}
