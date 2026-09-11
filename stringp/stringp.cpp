#include "stringp.hpp"

//Lowercase Conversion Method
void stringp::lower() {
    for(char& c : *this) {
        for(int i = 0; i < 26; i++) {
            if(c == alpha_Upper[i]) {
                c = alpha_Lower[i];
                break;
            }
        }
    }
}

//Uppercase Conversion Method
void stringp::upper() {
    for(char& c : *this) {
        for(int i = 0; i < 26; i++) {
            if(c == alpha_Lower[i]) {
                c = alpha_Upper[i];
                break;
            }
        }
    }
}

//Reversal Conversion Method
void stringp::reverse() {
    
}