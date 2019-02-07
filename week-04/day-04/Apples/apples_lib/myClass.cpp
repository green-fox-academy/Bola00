//
// Created by bolar on 2019. 02. 07..
//

#include "myClass.h"

std::string myClass::getApple()
{
    return "apple";
}

int myClass::sum (std::vector<int> numbers)
{
    int sum = 0;
    for ( int i = 0; i <numbers.size(); i ++){
        sum += numbers.at(i);
    }
    return sum;
}