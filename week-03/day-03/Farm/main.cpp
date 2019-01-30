#include <iostream>
#include <vector>
#include "Farm.h"
#include "Animal.h"
//Reuse your Animal class
//Create a Farm class
//it has list of Animals
//it has slots which defines the number of free places for animals
//breed() -> creates a new animal if there's place for it
//slaughter() -> removes the least hungry animal


int main() {

    Farm farm;

    std:: cout << farm.slaughter() << std:: endl;
    std::cout << farm.breed() << std:: endl;
    std::cout << farm.breed() << std:: endl;
    farm.farmanimals.at(0).play();
    farm.farmanimals.at(1).eat();
    std::cout << farm.breed() << std:: endl;
    std::cout << farm.breed() << std:: endl;
    std:: cout << farm.slaughter() << std:: endl;

    return 0;
}