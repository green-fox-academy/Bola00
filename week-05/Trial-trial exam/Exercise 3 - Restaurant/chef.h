//
// Created by bolar on 2019. 02. 13..
//

#ifndef EXERCISE_3_RESTAURANT_CHEF_H
#define EXERCISE_3_RESTAURANT_CHEF_H
#include "employees.h"
#include <map>
#include <algorithm>
#include <vector>
class Chef : public Employees
{
 public:
  Chef(std::string name);
  Chef(std::string name, int experience);
  void work() override;
  void cook(std::string foodName);
  int cookedNumber(std::string foodName);
  void introduce() override;
  std::string getFavoriteFood();
 private:
  std::map<std::string, int> _meals;
};

#endif //EXERCISE_3_RESTAURANT_CHEF_H
