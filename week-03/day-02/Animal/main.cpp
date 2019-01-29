#include <iostream>
#include "Animal.h"
//Create an Animal class
//Every animal has a hunger value, which is a whole number
//Every animal has a thirst value, which is a whole number
//when creating a new animal object these values are created with the default 50 value
//Every animal can eat() which decreases their hunger by one
//Every animal can drink() which decreases their thirst by one
//Every animal can play() which increases both by one



int main() {

    Animal Chubakka;
    Chubakka.eat();
    std::cout << Chubakka.hunger << std::endl;
    std::cout << Chubakka.thirst << std::endl;
    Chubakka.drink();
    std::cout << Chubakka.hunger << std::endl;
    std::cout << Chubakka.thirst << std::endl;
    Chubakka.play();
    std::cout << Chubakka.hunger << std::endl;
    std::cout << Chubakka.thirst << std::endl;

    return 0;
}