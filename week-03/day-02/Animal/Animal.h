//
// Created by bolar on 2019. 01. 29..
//
#include <iostream>
#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal {
public:
    int hunger;
    int thirst;


    Animal();
    void eat();
    void drink();

    void play();
};



#endif //ANIMAL_ANIMAL_H
