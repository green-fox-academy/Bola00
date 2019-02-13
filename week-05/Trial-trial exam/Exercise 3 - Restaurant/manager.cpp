//
// Created by bolar on 2019. 02. 13..
//

#include "manager.h"
Manager::Manager(std::string name)
:Employees(name)
{
    _moodLevel = 400;
}

Manager::Manager(std::string name, int experience)
:Employees(name, experience)
{
    _moodLevel = 400;
}

void Manager::work()
{
    _experience++;
}

void Manager::introduce()
{

    std::cout << "Hi, my name is " << _name << ". I'm a manager with "
              << _experience << " points of experience and I my mood level stands on " << _moodLevel << "." << std::endl;
}

void Manager::haveAMeeting()
{
    _moodLevel -= _experience;
}