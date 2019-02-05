//
// Created by bolar on 2019. 02. 05..
//

#include "mentor.h"

Mentor::Mentor()
{
 _level = JUNIOR;
}

Mentor::Mentor(std::string name, int age, Gender gender, Level level)
: Person (name, age, gender)
{
    _level = level;
}

void Mentor::introduce()
{
std::cout << "Hi, I'm "<< _name << ", a "<< _age <<" year old " <<getGender() <<" "<<getLevel() << " mentor." << std::endl;

}

void Mentor::getGoal()
{
   std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

std::string Mentor::getLevel()
{
    if (_level == JUNIOR)
        return "Junior";
    else if(_level == INTERMEDIATE)
        return "Intermediate";
    else if (_level == SENIOR)
        return "Senior";
}