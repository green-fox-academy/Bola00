#include <iostream>

void appendAFunc (std::string x){
    std::string xa = x + "a";

    std::cout << xa <<std::endl;
}

int main() {


    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    // - Write a function called `appendAFunc` that gets a string as an input,
    //   appends an 'a' character to its end and returns with a string
    //
    // - Print the result of `appendAFunc(typo)`

    std::string typo = "Chinchill";
    appendAFunc(typo);

    return 0;
}