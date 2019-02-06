//
// Created by bolar on 2019. 02. 06..
//

#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H
#include "animal.h"


class Mammal : public Animal
{
public:
    std::string breed();
    Mammal(std::string name);

private:
    int colour;
    int numOfLegs;


};


#endif //ZOO_MAMMAL_H
