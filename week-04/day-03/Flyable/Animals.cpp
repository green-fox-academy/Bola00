//
// Created by bolar on 2019. 02. 06..
//

#include "Animals.h"

std::string Animal::getName()
{
    return name;
}

Animal::Animal(std::string name)
{
    this->name = name;

}