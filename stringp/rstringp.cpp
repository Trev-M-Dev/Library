#include <string>
#include "stringp.hpp"

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

std::string stringp::r_reverse() {
    std::string reversed = "";
    char reversal[this->length()];
    int ln1 = (this->length()) - 1;
    for(char& c : *this) {
        reversal[ln1] = c;
        ln1--;
    }

    for(int i = 0; i < this->length(); i++) {
        reversed = reversed + reversal[i];
    }
    return reversed;
}
