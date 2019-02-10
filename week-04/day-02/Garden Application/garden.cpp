//
// Created by bolar on 2019. 02. 05..
//

#include "garden.h"
void Garden::addPlant(Garden *plant)
{
    plants.push_back(plant);
}

void Garden::watering(int amoungOfwater)
{
    std::cout<< "Watering with " << amoungOfwater <<" amount water." <<  std::endl;
    std::vector<Garden*> plantsWhoNeedWater;
    for (int i = 0; i < plants.size(); ++i) {
        if (plants.at(i)->needWater)
            plantsWhoNeedWater.push_back(plants.at(i));
    }

    int waterPerplant = amoungOfwater / plantsWhoNeedWater.size();

    for (int j = 0; j < plantsWhoNeedWater.size(); ++j) {
        plantsWhoNeedWater.at(j)->getWater(waterPerplant);
    }

    for (int i = 0; i < plants.size(); ++i) {
        plants.at(i)->checkWaterNeed();
    }
}

void Garden::checkWaterNeed()
{
    if (needWater)
        std:: cout << name << " needs water." << std::endl;
    else
        std:: cout << name << " doesn't need water." << std::endl;

}

Garden::Garden(std::string name)
{
    this->name = name;
    water = 0;
    needWater = true;
}

void Garden::getWater(int wateramount)
{
    water += wateramount;
}