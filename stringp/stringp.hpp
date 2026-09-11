#include <iostream>
#include <string>

//Inheritance From Standard "string" Class
class stringp : public std::string {
public:
    //Inherit Constructor
    std::string::string;
    //Static Variables
    static constexpr char alpha_Upper[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    static constexpr char alpha_Lower[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //Custom Methods
    void lower();
    void upper();
    void reverse();

};