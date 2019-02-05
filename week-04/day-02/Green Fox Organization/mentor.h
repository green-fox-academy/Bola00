//
// Created by bolar on 2019. 02. 05..
//

#ifndef GREEN_FOX_ORGANIZATION_MENTOR_H
#define GREEN_FOX_ORGANIZATION_MENTOR_H
#include "person.h"
#include <iostream>

enum Level{
    JUNIOR,
    INTERMEDIATE,
    SENIOR


};



class Mentor : public Person
{
public:
    Mentor();
    Mentor(std::string name, int age, Gender gender,Level level);
    std::string getLevel();
    void getGoal() override;
    void introduce() override;


private:
    Level _level;

};


#endif //GREEN_FOX_ORGANIZATION_MENTOR_H
