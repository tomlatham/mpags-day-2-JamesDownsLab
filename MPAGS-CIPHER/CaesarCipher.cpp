#include "CaesarCipher.hpp"

std::string runCaesarCipher(
        const std::string&inputText,
        const bool& encrypt,
        const int& key){
    std::string outputText;
    const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int pos{0};
    for (char i : inputText){
        pos = 0;
        for (char j : alphabet){
            if (i==j){
                if (encrypt){
                    outputText += alphabet[(pos+key)%alphabet.size()];
                } else{
                    outputText += alphabet[(pos - key)%alphabet.size()];
                }
                break;
            }
            ++pos;
        }
    }
    return outputText;
}