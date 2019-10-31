#include "CaesarCipher.hpp"

std::string runCaesarCipher(
        const std::string& inputText,
        const bool& encrypt,
        const std::size_t& key){

    std::string outputText;

    const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::string::size_type alphabetSize{alphabet.size()};

    for (char i : inputText){
        for (std::size_t pos{0}; pos < alphabetSize; ++pos){
            if (alphabet[pos]==i){
                if (encrypt){
                    outputText += alphabet[(pos + key)%alphabetSize];
                } else{
                    outputText += alphabet[(alphabetSize + pos - key)%alphabetSize];
                }
                break;
            }
        }
    }
    return outputText;
}
