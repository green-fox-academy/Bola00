//
// Created by bolar on 2019. 02. 13..
//

#ifndef EXERCISE_3_RESTAURANT_MANAGER_H
#define EXERCISE_3_RESTAURANT_MANAGER_H
#include "employees.h"
class Manager : public Employees
{
 public:
  Manager(std::string name);
  Manager(std::string name, int experience);
  void work() override;
  void introduce() override;
  void haveAMeeting();

 private:
  int _moodLevel;
};

#endif //EXERCISE_3_RESTAURANT_MANAGER_H
