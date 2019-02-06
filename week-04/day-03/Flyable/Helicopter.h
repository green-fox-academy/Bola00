//
// Created by bolar on 2019. 02. 06..
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H
#include "flyable.h"
#include "Vehicle.h"


class Helicopter : Flyable
{
public:
    Helicopter();
    void land();
    void fly();
    virtual void takeOff();
};


#endif //FLYABLE_HELICOPTER_H
