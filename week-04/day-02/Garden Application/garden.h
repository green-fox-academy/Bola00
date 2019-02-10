//
// Created by bolar on 2019. 02. 05..
//

#ifndef GARDEN_APPLICATION_GARDEN_H
#define GARDEN_APPLICATION_GARDEN_H
#include <vector>
#include <iostream>

class Garden
{
public:
    Garden(std::string name);
    void addPlant(Garden *plant);
    void watering(int amoungOfwater);
    virtual void checkWaterNeed();
protected:
    std::string name;
    virtual void getWater(int wateramount);
    int water;
    bool needWater;
private:
    std::vector<Garden*>plants;

};


#endif //GARDEN_APPLICATION_GARDEN_H
