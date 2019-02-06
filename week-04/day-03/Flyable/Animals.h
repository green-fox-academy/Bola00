//
// Created by bolar on 2019. 02. 06..
//

#ifndef FLYABLE_ANIMALS_H
#define FLYABLE_ANIMALS_H
#include <iostream>


class Animal
{
public:
    Animal(std::string name);
    std::string getName();
    virtual std::string breed()=0;

protected:
    std::string name;
    int age;

};


#endif //ZOO_ANIMAL_H
