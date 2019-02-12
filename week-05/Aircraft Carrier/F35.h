//
// Created by bolar on 2019. 02. 11..
//

#ifndef AIRCRAFT_CARRIER_F35_H
#define AIRCRAFT_CARRIER_F35_H
#include "aircraft.h"

class F35 : public Aircraft
{
public:
    F35();
    std::string getType() override;
    bool isPriority() override;


};


#endif //AIRCRAFT_CARRIER_F35_H
