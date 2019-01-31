#include <iostream>

// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
// (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
// have 3 ears, because they each have a raised foot. Recursively return the
// number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).
int earsCounter (int n){
    if (n == 0){
        return 0;
    }
    else if(n % 2 == 1){
        return ( 2 + earsCounter(n-1) );
    }
    else{
        return ( 3 + earsCounter(n-1) );
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