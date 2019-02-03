//
// Created by bolar on 2019. 02. 01..
//

#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H
#include "Pirate.h"
#include <iostream>
#include <vector>
#include <time.h>

class Ship
{
public:

  void fillShip(); //with pirates and a captain who has a parrot
  void status(); // write out the status of the ship
  int alivePirates();
  bool shipBattle(Ship otherShip); //if its equal the attacker win




private:
    int calculateScore(); //power of the ship calculator
    void wakeUpPirate(); // the pirates who has parrots are waked up by their pets before a fight and they head gonna be clear
    void winParrots(int parrots); //a ship get some parrots
    int loseParrots(); // a ship lose all his parrots
    void wining();
    void losing();
    std::vector<Pirate> piratesOfShip;
    Pirate Captain;
};


#endif //PIRATES_SHIP_H
