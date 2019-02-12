//
// Created by bolar on 2019. 02. 11..
//

#ifndef AIRCRAFT_CARRIER_F16_H
#define AIRCRAFT_CARRIER_F16_H
#include "aircraft.h"


class F16 : public Aircraft
{
public:
    F16();
    std::string getType() override;
    bool isPriority() override;

};


#endif //AIRCRAFT_CARRIER_F16_H
