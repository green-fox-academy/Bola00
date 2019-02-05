//
// Created by bolar on 2019. 02. 05..
//

#ifndef GREEN_FOX_ORGANIZATION_PERSON_H
#define GREEN_FOX_ORGANIZATION_PERSON_H
#include <iostream>

enum Gender {MALE, FEMALE, OTHER};

class Person {
public:
   Person();
   Person(std::string name, int age, Gender gender);
   std::string getGender();
   virtual void introduce();
   virtual void getGoal();

protected:
    std::string _name;
    int _age;
    Gender _gender;

};


#endif //GREEN_FOX_ORGANIZATION_PERSON_H
