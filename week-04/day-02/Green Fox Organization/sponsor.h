//
// Created by bolar on 2019. 02. 05..
//

#ifndef GREEN_FOX_ORGANIZATION_SPONSOR_H
#define GREEN_FOX_ORGANIZATION_SPONSOR_H
#include <iostream>
#include "person.h"

class Sponsor : public Person
{
public:
   void introduce() override;
   void hire();
   void getGoal() override;
   Sponsor();
   Sponsor(std:: string name, int age, Gender gender, std::string company);

private:
    std::string _company;
    int _hiredStudents;

};


#endif //GREEN_FOX_ORGANIZATION_SPONSOR_H
