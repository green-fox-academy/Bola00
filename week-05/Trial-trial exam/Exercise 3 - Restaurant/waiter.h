//
// Created by bolar on 2019. 02. 13..
//

#ifndef EXERCISE_3_RESTAURANT_WAITER_H
#define EXERCISE_3_RESTAURANT_WAITER_H
#include "employees.h"
class Waiter : public Employees
{
 public:
  Waiter(std::string name);
  Waiter(std::string name, int experience);
  void work() override;
  int getTips();
  void introduce() override;
 private:
  int _tips;

};

#endif //EXERCISE_3_RESTAURANT_WAITER_H
