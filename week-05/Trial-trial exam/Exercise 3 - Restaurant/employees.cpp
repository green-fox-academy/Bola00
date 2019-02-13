//
// Created by bolar on 2019. 02. 13..
//

#include "employees.h"
Employees::Employees(std::string name)
{
    _name = name;
    _experience = 0;
}

Employees::Employees(std::string name, int experience)
{
    _name = name;
    _experience = experience;
}

