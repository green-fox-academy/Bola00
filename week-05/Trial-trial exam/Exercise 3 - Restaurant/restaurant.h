//
// Created by bolar on 2019. 02. 13..
//

#ifndef EXERCISE_3_RESTAURANT_RESTAURANT_H
#define EXERCISE_3_RESTAURANT_RESTAURANT_H
#include <iostream>
#include "employees.h"
#include <vector>

class Restaurant
{
 public:
    Restaurant(std::string name, int yearOfFounded);
     void guestsArrived(); //call the employees to work
     void hire(Employees* employee);
     void everybodyIntroduce();
 private:
     std::string _name;
     int _yearOfFounded;
     std::vector<Employees*> _employees;

};

#endif //EXERCISE_3_RESTAURANT_RESTAURANT_H
