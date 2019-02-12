//
// Created by bolar on 2019. 02. 11..
//

#include "Carrier.h"
Carrier::Carrier(int ammo, int health)
{
    _carrierAmmo = ammo;
    _health = health;

}

void Carrier::add(Aircraft* aircraftOne)
{
    aircrafts.push_back(aircraftOne);

}

void Carrier::fill() {
    try {
        for (int i = 0; i < aircrafts.size(); i++)
            if (aircrafts.at(i)->isPriority()) {
                if(_carrierAmmo == 0){
                    throw 99;
                }
                aircrafts.at(i)->refill(_carrierAmmo);
            }

        for (int i = 0; i < aircrafts.size(); i++)
            if (!aircrafts.at(i)->isPriority()) {
                if(_carrierAmmo == 0){
                    throw 99;
                }
                aircrafts.at(i)->refill(_carrierAmmo);
            }
    }catch (int number){
        std::cout <<" Out of Ammo!" << std::endl;
    }
}

void Carrier:: fight(Carrier &otherCarrier)
{
    int Damage = 0;

    for (int i = 0; i < aircrafts.size(); i++){
        Damage += aircrafts.at(i)->fight();

        otherCarrier._health -= Damage;
    }

}

std::string Carrier::getStatus()
{
    if (_health <= 0){
        return "It's dead Jim :(";
    }
    std::string result;
    std::string CarrierStatus = "HP: " + std::to_string(_health)
            + " , Aircraft count: " + std::to_string(aircrafts.size()) +" , Ammo Storage: " + std::to_string(_carrierAmmo)
            + ", Total damage: " + std::to_string(totalDamage()) + ". \n  Aircrafts: \n";

    result += CarrierStatus;

    for (int i = 0; i < aircrafts.size(); ++i) {
    std:: string aircraftStatus = "Type " + aircrafts.at(i)->getType() + ", Ammo: "
            + std::to_string (aircrafts.at(i)->getAmmo())
            + ", Base Damage: " + std::to_string(aircrafts.at(i)->getBaseDamage()) +", All Damage: "
            + std::to_string(aircrafts.at(i)->DamageCalculate()) + ". \n";

        result += aircraftStatus;
    }

    return result;
}

int Carrier::totalDamage()
{
    int damage = 0;

    for (int i = 0; i < aircrafts.size(); ++i) {
     damage += aircrafts.at(i)->DamageCalculate();
    }

    return damage;
}
