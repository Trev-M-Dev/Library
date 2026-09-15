/*MUTATOR METHODS FOR "stringp" CLASS*/
#include "stringp.hpp"
#include <string>
//Mutator Lowercase Conversion Method (ASCII Replacement Under Development)
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
// Mutator Uppercase Conversion Method (ASCII Replacement Under Development)
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
//Mutator Reversal Conversion Method
void stringp::reverse() {
    char reversed[this->length()];
    int ln1 = (this->length()) - 1;
    for(char& c : *this) {
        reversed[ln1] = c;
        ln1--;
    }
    int ln2 = 0;
    for(char& c : *this) {
        c = reversed[ln2];
        ln2++;
    }
}