//
// Created by bolar on 2019. 02. 11..
//

#ifndef AIRCRAFT_CARRIER_AIRCRAFT_H
#define AIRCRAFT_CARRIER_AIRCRAFT_H

#include <string>

class Aircraft
{
public:
    Aircraft();
    int fight();
    int refill(int& ammoPackage);
    virtual std::string getType();
    std::string getStatus();
    virtual bool isPriority()=0;
    int DamageCalculate();
    int getAmmo();
    int getBaseDamage();
protected:
    int _ammo;
    int _maxAmmo;
    int _baseDamage;

};


#endif //AIRCRAFT_CARRIER_AIRCRAFT_H
