//
// Created by bolar on 2019. 01. 30..
//

#include <iostream>
#include "Animal.h"

Animal::Animal()
{
    hunger = 50;
    thirst = 50;
}

void Animal::eat()
{
    hunger--;
}
void Animal::drink()
{
    thirst--;
}
void Animal::play()
{
    hunger++;
    thirst++;
}