//
// Created by bolar on 2019. 02. 03..
//

#include "BattleApp.h"

BattleApp::BattleApp()
{
    Ship one;
    one.fillShip();
    std::cout << std::endl;
    Ship two;
    two.fillShip();
    std::cout << std::endl;
    one.shipBattle(two);
}