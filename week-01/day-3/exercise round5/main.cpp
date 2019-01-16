#include <iostream>

int main() {
    //18 OddEven
    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.

    int nm;
    std::cout <<"Give me a number: ";
    std::cin >> nm;
    if (nm % 2 == 1){
        std::cout << "Your number is odd" <<std::endl;
    }
    else{
        std::cout << "Your number is even" <<std::endl;
    }
    //19 OneTwoALot
    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot

    int num;
    std::cout <<"Give me another number: ";
    std::cin >> num;

    if (num <= 0) {
        std::cout << "Not enough";
    } else if (num == 1){
        std::cout <<"One";
    } else if (num == 2){
        std::cout <<"Two";
    } else if (num > 2) {
        std::cout <<"A lot";
    }

    return 0;
}