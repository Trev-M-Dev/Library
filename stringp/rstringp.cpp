/*ACCESSOR METHODS FOR "stringp" CLASS*/
#include <string>
#include <vector>
#include "stringp.hpp"
//Accessor Lowercase Conversion Method (ASCII Replacement Under Development)
std::string stringp::r_lower() {
    std::string temp = *this;
    for(int i = 0; i < this->length(); i++) {
        for(int j = 0; j < 26; j++) {
            if(temp[i] == alpha_Upper[j]) {
                temp[i] = alpha_Lower[j];
                break;
            }
        }
    }
    return temp;
}
//Accessor Uppercase Conversion Method (ASCII Replacement Under Development)
std::string stringp::r_upper() {
    std::string temp = *this;
    for(int i = 0; i < this->length(); i++) {
        for(int j = 0; j < 26; j++) {
            if(temp[i] == alpha_Lower[j]) {
                temp[i] = alpha_Upper[j];
                break;
            }
        }
    }
    return temp;
}
//Accessor Reverse Conversion Method
std::string stringp::r_reverse() {
    std::string reversed;
    char reversal[this->length()];
    int ln1 = (this->length()) - 1;
    for(char& c : *this) {
        reversal[ln1] = c;
        ln1--;
    }

    for(int i = 0; i < this->length(); i++) {
        reversed += reversal[i];
    }
    return reversed;
}
//Accessor Split Method
std::vector<std::string> stringp::split() {
    std::vector<std::string> tokens;
    std::string token;
    for(char& c : *this) {
        if(c == ' ') {
            if(!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }
    //Last Token Handling
    if(!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}
