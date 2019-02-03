//
// Created by bolar on 2019. 02. 01..
//

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H
#include <iostream>
#include <time.h>

class Pirate
{
public:
    Pirate(); //basic stuff of the pirate
    void drinkSomeRum();
    void howsItGoingMate(); //we can ask the pirate how he feel himself
    void die();
    void brawl(Pirate another);
    void getParrot();
    void loseParrot();
    std::string statusinfo();
    int getDrunkLevel();
    bool parrotStatus();
    void wakingUp();

//private:
    int _drunknessLevel;
    std::string _status;
    bool _parrot;
};


#endif //PIRATES_PIRATE_H
