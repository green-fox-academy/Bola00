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
    int space = a - 1;
    for(int i = 1; i <=a/2+1; i++){
        for (int c = 0; c<=space; c++){
            std::cout<<" ";
            space--;}
        for (int u = 1; u<=2 * i - 1 ; u++){
            std::cout<<"*";
            }
        std::cout<< std::endl;}
    for (int i = 1; i <=a/2; i++) {
        space = 1;
        for (int c = i; c>=space; c--){
            std::cout<<" ";
            space++;}
        for (int u = a; u>=2 * i ; u--){
            std::cout<<"*";}


     std::cout<< std::endl;
    }
    return 0;
}