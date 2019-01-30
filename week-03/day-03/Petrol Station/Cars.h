//
// Created by bolar on 2019. 01. 30..
//

#ifndef PETROL_STATION_CARS_H
#define PETROL_STATION_CARS_H
#include <iostream>

class Cars {
public:
    Cars(int gas, int tank);
    bool isFull();
    void fill();

private:
    int Cgas_amount;
    int capacity;
};


#endif //PETROL_STATION_CARS_H
