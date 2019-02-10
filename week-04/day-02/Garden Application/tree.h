//
// Created by bolar on 2019. 02. 10..
//

#ifndef GARDEN_APPLICATION_TREE_H
#define GARDEN_APPLICATION_TREE_H
#include "garden.h"

class Tree : public Garden
{
public:
    Tree(std::string name);
    void checkWaterNeed() override;
private:
    void getWater(int wateramount)override;
};


#endif //GARDEN_APPLICATION_TREE_H
