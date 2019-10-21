#include "CaesarCipher.hpp"

std::string encryptCaesarCipher(
    const std::string& inputText,
    const int& key){
    std::string outputText;
    const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int position{0};
    for (char i : inputText){
        position = 0;
        for (char j : alphabet){
            if (i == j){
                outputText += alphabet[(position + key)%alphabet.size()];
                break;
            }
            ++position;
        }
    }
    return outputText;
}

std::string decryptCaesarCipher(
    const std::string& inputText,
    const int& key){
    std::string outputText;
    const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int position{0};
    for (char i : inputText){
        position = 0;
        for (char j : alphabet){
            if (i==j){
                outputText += alphabet[(position - key)%alphabet.size()];
                break;
            }
            ++position;
        }
    }
    return outputText;
}

std::string runCaesarCipher(
    const std::string& inputText,
    const bool& encrypt,
    const int& key){
    if (encrypt){
        return encryptCaesarCipher(inputText, key);
    }
    else{
        return decryptCaesarCipher(inputText, key);
    }
}