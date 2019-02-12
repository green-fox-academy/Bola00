//
// Created by bolar on 2019. 02. 11..
//

#ifndef AIRCRAFT_CARRIER_CARRIER_H
#define AIRCRAFT_CARRIER_CARRIER_H
#include "aircraft.h"
#include <vector>
#include <iostream>
class Carrier
{
public:
    Carrier(int ammo, int health);
    void add(Aircraft *aircraftOne);
    void fill();
    void fight(Carrier &otherCarrier);
    std::string getStatus();
    int totalDamage();

private:
    std::vector<Aircraft*>aircrafts;
    int _carrierAmmo;
    int _health;

};


#endif //AIRCRAFT_CARRIER_CARRIER_H
