#include <iostream>

// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).
int earsCounter (int n){
    if (n == 1){
        return 2;
    } else{
        return ( 2 + earsCounter(n-1) );
    }
}

int main() {

    int bunniesNum;

    std::cout << "IT'S Bunny time!" <<std::endl;
    std::cout << "How many bunnies do you have?: ";
    std::cin >>  bunniesNum;

    std::cout << "Your bunnies have " << earsCounter(bunniesNum) << " big floppy ears!";


    return 0;
}