//
// Created by bolar on 2019. 02. 05..
//

#ifndef GREEN_FOX_ORGANIZATION_STUDENT_H
#define GREEN_FOX_ORGANIZATION_STUDENT_H
#include <iostream>
#include "person.h"


class Student : public Person
{
    public:
    Student();
    Student(std::string name, int age, Gender gender, std::string previousOrganization);
    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);

    private:
    std::string _previousOrganization;
    int _skippedDays;
};


#endif //GREEN_FOX_ORGANIZATION_STUDENT_H
