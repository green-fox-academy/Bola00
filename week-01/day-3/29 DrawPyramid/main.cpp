#include <iostream>

int main() {
    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was
int a;
    std::cout << "A pyramid for a number?" << std::endl << "Number: ";
    std::cin >> a;
    std::cout<<"Pyramid:" <<std::endl;
    for (int i = 1; i<=a; i++){
        for (int u =1; u<a-i+1; u++) {
            std::cout <<" ";
        }for (int k = 1; k<i*2; k++){
            std::cout<<"*";
        }for (int u =1; u<a-i+1; u++) {
            std::cout <<" ";
        }std::cout<<std::endl;
        }
        return 0;
}