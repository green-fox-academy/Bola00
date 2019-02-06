//
// Created by bolar on 2019. 02. 06..
//

#include "reptile.h"

std::string Reptile::breed()
{
    return "laying eggs.";
}

Reptile::Reptile(std::string name)
: Animal(name) {}