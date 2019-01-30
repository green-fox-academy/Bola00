//
// Created by bolar on 2019. 01. 30..
//

#ifndef PETROL_STATION_STATION_H
#define PETROL_STATION_STATION_H
#include <iostream>
#include "Cars.h"


class Station {
    public:
    Station();

    std::string fill(Cars &car);

    private:
    int Sgas_amount;

};


#endif //PETROL_STATION_STATION_H
