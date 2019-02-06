//
// Created by bolar on 2019. 02. 06..
//

#include "birds.h"
std::string Bird::breed()
{
    return "laying eggs.";
}

Bird::Bird(std::string name)
:Animal(name){}