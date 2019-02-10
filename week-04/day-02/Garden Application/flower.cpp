//
// Created by bolar on 2019. 02. 10..
//

#include "flower.h"
Flower::Flower(std::string name)
:  Garden(name)
{}

void Flower::checkWaterNeed()
{

    if (water < 5) {
        std::cout << name << " needs water." << std::endl;
    } else{
        needWater = false;
        std:: cout << name << " doesn't need water." << std::endl;
    }
}

void Flower::getWater(int wateramount)
{
    water += (wateramount / 4 * 3);
}