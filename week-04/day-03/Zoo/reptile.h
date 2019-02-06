//
// Created by bolar on 2019. 02. 06..
//

#ifndef ZOO_REPTILE_H
#define ZOO_REPTILE_H
#include "animal.h"

class Reptile : public Animal
{
public:
    std::string breed();
    Reptile(std::string name);

private:
    int happyness;
    std::string colour;
    bool doesItCare;

};


#endif //ZOO_REPTILE_H
