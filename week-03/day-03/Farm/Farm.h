//
// Created by bolar on 2019. 01. 30..
//

#ifndef FARM_FARM_H
#define FARM_FARM_H
#include <iostream>
#include <vector>
#include "Animal.h"


class Farm {
public:
int slots;
std::vector<Animal> farmanimals;


Farm ();

std::string breed ();
std::string slaughter();
};


#endif //FARM_FARM_H
