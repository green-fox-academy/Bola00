#include <iostream>

int main() {
    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int chickens;
    int pigs;

    std::cout<<"how many chickens does the farmer have? TYPE: ";
    std::cin >> chickens;
    std::cout<<"and how many pigs does he have? TYPE: ";
    std::cin >> pigs;

    std::cout << "Do you know how much legs it? It is " << (chickens * 2) + (pigs * 4)
    <<" legs if we not count that Bonny piggy lost 1 of her leg." <<std::endl;
    return 0;
}