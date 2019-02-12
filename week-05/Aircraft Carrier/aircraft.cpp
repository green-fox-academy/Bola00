//
// Created by bolar on 2019. 02. 11..
//

#include "aircraft.h"
Aircraft::Aircraft()
{
    _ammo = 0;
}


int Aircraft::fight()
{
    int damage = _ammo * _baseDamage;
    _ammo = 0;

    return damage;

}

int Aircraft::refill(int& ammoPackage)
{
    int ammoToMax = _maxAmmo - _ammo;

    while (ammoToMax != 0 && ammoPackage != 0){
        _ammo++;
        ammoToMax--;
        ammoPackage--;
    }

    return ammoPackage;
}

std::string Aircraft::getType()
{
   return "noname";
}

std::string Aircraft:: getStatus()
{

    return ("Type" + getType() + ", Ammo: " + std::to_string(_ammo)
    + ", Base Damage: " + std::to_string(_baseDamage) + ", All Damage: " + std::to_string(_ammo * _baseDamage)+ "\n");
}

int Aircraft::DamageCalculate()
{
    return (_baseDamage * _ammo);
}

int Aircraft::getAmmo()
{
    return _ammo;
}

int Aircraft::getBaseDamage()
{
    return _baseDamage;
}