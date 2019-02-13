//
// Created by bolar on 2019. 02. 13..
//

#ifndef EXERCISE_3_RESTAURANT_EMPLOYEES_H
#define EXERCISE_3_RESTAURANT_EMPLOYEES_H
#include <iostream>

class Employees
{
 public:
  Employees(std::string name);
  Employees(std::string name, int experience);
  virtual void work() = 0;
  virtual void introduce()=0;
 protected:
  std::string _name;
  int _experience;
};

#endif //EXERCISE_3_RESTAURANT_EMPLOYEES_H
