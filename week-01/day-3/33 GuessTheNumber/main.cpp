#include <iostream>

int main() {
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8


    int a;

    std::cout<<"Give me a number: ";
    std::cin>>a;
    a = a * 2 + 4;
    std::cout<<"I changed your number. Guess what is the new number!" <<std::endl;



    for ( ; ; ){
        int b;
        std::cout<<"Number: ";
        std::cin>>b;
        if (b < a){
            std::cout<<"The stored number is higher" <<std::endl;
        }else if (b > a){
            std::cout<<"The stored number is lower" <<std::endl;
        }else if (b == a){
            std::cout<< "You found the number: "<< a <<std::endl;
            return 0;
        }
    }

}