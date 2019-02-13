//
// Created by bolar on 2019. 02. 13..
//

#include "waiter.h"
void Waiter::work()
{
    _tips++;
    _experience++;


}

Waiter::Waiter(std::string name)
: Employees(name)
{
    _tips = 0;
}

Waiter::Waiter(std::string name, int experience)
: Employees(name, experience)
{
    _tips = 0;
}

int Waiter::getTips()
{
    return _tips;
}

void Waiter::introduce()
{
 std::cout <<"Hi, my name is " << _name <<". I'm a waiter with "
 << _experience <<" points of experience and I got " << _tips << " dollars for tips." << std::endl;
}