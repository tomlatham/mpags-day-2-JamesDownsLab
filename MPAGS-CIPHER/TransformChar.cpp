#include "TransformChar.hpp"

std::string transformChar(const char in_char){
  /* Transform the input characters to the required input.
  
  All letters are returned uppercase.
  All digits are returned as the uppercase spelling of their number.
  All other symbols are ignored.
  */

  // Uppercase alphabetic characters
  std::string out_string {""};

  if (std::isalpha(in_char)) {
    out_string = std::toupper(in_char);
  }
  else {
    // Transliterate digits to English words
    switch (in_char) {
      case '0':
        out_string = "ZERO";
        break;
      case '1':
        out_string = "ONE";
        break;
      case '2':
        out_string = "TWO";
        break;
      case '3':
        out_string = "THREE";
        break;
      case '4':
        out_string = "FOUR";
        break;
      case '5':
        out_string = "FIVE";
        break;
      case '6':
        out_string = "SIX";
        break;
      case '7':
        out_string = "SEVEN";
        break;
      case '8':
        out_string = "EIGHT";
        break;
      case '9': 
        out_string = "NINE";
        break;
      default:
        out_string = "";
        break;
    }
  }
  return out_string;
}