#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

std::string runCaesarCipher(
    const std::string& inputText,
    const bool& encrypt,
    const std::size_t& key);

#endif 
