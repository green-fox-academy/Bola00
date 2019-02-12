//
// Created by bolar on 2019. 02. 11..
//

#include "F35.h"
F35::F35()
{
    _maxAmmo = 12;
    _baseDamage = 50;
}

std::string F35::getType()
{
    return "F35";
}

bool F35::isPriority()
{
    return true;
}