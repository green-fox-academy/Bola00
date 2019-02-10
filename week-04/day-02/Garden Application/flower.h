//
// Created by bolar on 2019. 02. 10..
//

#ifndef GARDEN_APPLICATION_FLOWER_H
#define GARDEN_APPLICATION_FLOWER_H
#include "garden.h"

class Flower : public Garden
{
public:
    Flower(std::string name);
    void checkWaterNeed() override;
private:
    void getWater(int wateramount)override;


};


#endif //GARDEN_APPLICATION_FLOWER_H
