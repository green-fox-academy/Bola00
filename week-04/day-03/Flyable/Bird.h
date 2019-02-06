//
// Created by bolar on 2019. 02. 06..
//

#ifndef FLYABLE_BIRD_H
#define FLYABLE_BIRD_H
#include "Animals.h"
#include "flyable.h"


class Bird : public Animal, public Flyable
{
public:
    std::string breed();
    Bird(std::string name);
    void land();
    void fly();
    virtual void takeOff();

private:
    int happyness;
    std::string colour;
    bool doesItCare;

};


#endif //FLYABLE_BIRD_H
