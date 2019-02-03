//
// Created by bolar on 2019. 02. 03..
//

#ifndef PIRATES_ARMADA_H
#define PIRATES_ARMADA_H
#include <iostream>
#include "Ship.h"


class Armada {
public:
    Armada();
    bool armadaWar(Armada other_armada);

private:
    std::vector<Ship> ships;
};


#endif //PIRATES_ARMADA_H
