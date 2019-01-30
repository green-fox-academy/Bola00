//
// Created by bolar on 2019. 01. 30..
//

#include <iostream>
#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal
{
public:
    int hunger;
    int thirst;


    Animal();
    void eat();
    void drink();

    void play();
};

#endif //FARM_ANIMAL_H
