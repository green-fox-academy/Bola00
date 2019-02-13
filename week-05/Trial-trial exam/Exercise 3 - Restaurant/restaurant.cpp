//
// Created by bolar on 2019. 02. 13..
//

#include "restaurant.h"
void Restaurant::guestsArrived()
{
    for (int i = 0; i < _employees.size(); ++i)
        _employees.at(i)->work();

}

Restaurant::Restaurant(std::string name, int yearOfFounded)
{
    _name = name;
    _yearOfFounded = yearOfFounded;
}

void Restaurant::hire(Employees* employee)
{
    _employees.push_back(employee);

}

void Restaurant::everybodyIntroduce()
{

    for (int i = 0; i < _employees.size(); ++i) {
        _employees.at(i)->introduce();
    }

}
