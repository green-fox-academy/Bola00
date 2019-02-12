//
// Created by bolar on 2019. 02. 11..
//

#include "F16.h"
F16::F16()
{
    _maxAmmo = 8;
    _baseDamage = 30;
}

std::string F16::getType()
{
    return "F16";
}

bool F16::isPriority()
{
    return false;
}