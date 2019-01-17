#include <iostream>

int main() {
    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was

    int a;
    std::cout << "A triangle for a number?" << std::endl << "Number: ";
    std::cin >> a;
    std::cout<<"Triangle:" <<std::endl;
    for (int i = 1; i<=a; i++){
                for (int u =1; u<=i; u++){
            std::cout<<"*";
            }std::cout << std::endl;
    }

    return 0;
}