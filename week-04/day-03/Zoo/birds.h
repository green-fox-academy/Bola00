//
// Created by bolar on 2019. 02. 06..
//

#ifndef ZOO_BIRDS_H
#define ZOO_BIRDS_H
#include "animal.h"


class Bird : public Animal
{
public:
    std::string breed();
    Bird(std::string name);

private:
    int happyness;
    std::string colour;
    bool doesItCare;

};


#endif //ZOO_BIRDS_H
