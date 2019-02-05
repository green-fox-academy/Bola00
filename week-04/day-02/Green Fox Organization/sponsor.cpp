//
// Created by bolar on 2019. 02. 05..
//

#include "sponsor.h"

void Sponsor::introduce()
{
    std::cout << "Hi, I'm "<< _name << ", a "<< _age <<" year old "<<getGender()
    <<" who represents "<< _company <<" and hired " << _hiredStudents <<" students so far." << std::endl;
}

void Sponsor::hire()
{
    _hiredStudents++;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}

Sponsor::Sponsor()
{
    _company = "Google";
}

Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company)
:Person(name, age, gender)
{
   _company = company;

}