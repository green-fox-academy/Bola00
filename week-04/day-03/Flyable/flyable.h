//
// Created by bolar on 2019. 02. 06..
//

#ifndef FLYABLE_FLYABLE_H
#define FLYABLE_FLYABLE_H
#include <iostream>

class Flyable {
public:
    virtual void land()=0;
    virtual void fly()=0;
    virtual void takeOff()=0;

protected:
    bool isItFly;

};


#endif //FLYABLE_FLYABLE_H
