//
// Created by bolar on 2019. 02. 10..
//

#include "tree.h"
Tree::Tree(std::string name)
: Garden(name)
{}

void Tree::checkWaterNeed()
{
    if (water < 10)
        std:: cout << name << " needs water." << std::endl;
    else{
        needWater = false;
    std:: cout << name << " doesn't need water." << std::endl;
    }
}

void Tree::getWater(int wateramount)
{
    water += (wateramount / 10 * 4);
}