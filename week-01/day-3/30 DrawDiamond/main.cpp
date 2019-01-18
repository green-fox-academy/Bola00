#include <iostream>

int main() {
    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    int a;
    std::cout<<"diamond for a number? " <<std::endl << "Number: ";
    std::cin>> a;
    std::cout <<"Diamond:" <<std::endl;
    for (int i = 1; i<=a; i++){
        for (int u =1; u<a-i+1; u++) {
            std::cout <<" ";
        }for (int k = 1; k<i*2; k++) {
            std::cout << "*";

        }std::cout<<std::endl;
    }
    for (int i = 1; i<=a-1; i++){
        for (int u = a-1; u>a-i-1; u--) {
            std::cout <<" ";
        }for (int k = a*2-1; k>i*2; k--) {
            std::cout << "*";

        }std::cout<<std::endl;
    }
    return 0;
}