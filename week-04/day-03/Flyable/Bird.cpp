//
// Created by bolar on 2019. 02. 06..
//

#include "Bird.h"

std::string Bird::breed()
{
    return "laying eggs.";
}

Bird::Bird(std::string name)
:Animal(name)
{
    isItFly = false;
}

void Bird::fly()
{
    if(isItFly)
        std::cout << "It is flying!" << std::endl;
    else
        std::cout << "It is not flying!" << std::endl;

}

void Bird::land()
{
    isItFly = false;
}

void Bird::takeOff()
{
    isItFly = true;
}