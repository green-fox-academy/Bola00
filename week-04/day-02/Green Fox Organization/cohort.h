//
// Created by bolar on 2019. 02. 05..
//

#ifndef GREEN_FOX_ORGANIZATION_COHORT_H
#define GREEN_FOX_ORGANIZATION_COHORT_H
#include "student.h"
#include "mentor.h"
#include <vector>

class Cohort
{
public:
    Cohort(std::string name);
    void addStudent(Student* student);
    void addMentor(Mentor* mentor);
    void info();

private:
    std::string _name;
    std::vector<Student*> _students;
    std::vector<Mentor*> _mentors;

};


#endif //GREEN_FOX_ORGANIZATION_COHORT_H
