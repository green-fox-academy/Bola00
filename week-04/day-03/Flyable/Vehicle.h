//
// Created by bolar on 2019. 02. 06..
//

#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H
#include <iostream>

class Vehicle
{
public:
Vehicle (std::string colour);

protected:
    std::string colour;
    int size;
    bool isItCare;

};


#endif //FLYABLE_VEHICLE_H
