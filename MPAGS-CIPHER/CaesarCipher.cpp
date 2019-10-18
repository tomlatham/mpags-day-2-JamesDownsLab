#include "CaesarCipher.hpp"

std::string encryptCaesarCipher(
    const std::string& inputText
)
{
    return inputText;
}

std::string decryptCaesarCipher(
    const std::string& inputText
)
{
    return inputText;
}

std::string runCaesarCipher(
    const std::string& inputText,
    const bool encrypt){
    if (encrypt){
        return encryptCaesarCipher(inputText);
    }
    else{
        return decryptCaesarCipher(inputText);
    }
}