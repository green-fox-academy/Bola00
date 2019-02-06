//
// Created by bolar on 2019. 02. 06..
//

#include "Helicopter.h"
Helicopter::Helicopter()
{
    isItFly = false;
}

void Helicopter::fly()
{
    if(isItFly)
        std::cout << "It is flying!" << std::endl;
    else
        std::cout << "It is not flying!" << std::endl;

}

void Helicopter::land()
{
    isItFly = false;
}

void Helicopter::takeOff()
{
    isItFly = true;
}