#include "CaesarCipher.hpp"

std::string encryptCaesarCipher(
    const std::string& inputText,
    const int& key){
    std::string outputText;
    for (std::string::size_type i = 0; i < inputText.size(); ++i){
        outputText += inputText[(i + key)%inputText.size()];
    }
    return outputText;
}

std::string decryptCaesarCipher(
    const std::string& inputText
)
{
    return inputText;
}

std::string runCaesarCipher(
    const std::string& inputText,
    const bool& encrypt,
    const int& key){
    if (encrypt){
        return encryptCaesarCipher(inputText, key);
    }
    else{
        return decryptCaesarCipher(inputText);
    }
}