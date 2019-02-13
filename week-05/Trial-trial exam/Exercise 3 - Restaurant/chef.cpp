//
// Created by bolar on 2019. 02. 13..
//

#include "chef.h"
void Chef::work()
{
    _experience++;
}

Chef::Chef(std::string name)
    : Employees(name)
{}

Chef::Chef(std::string name, int experience)
    : Employees(name, experience)
{}

void Chef::cook(std::string foodName)
{
    if (_meals.find(foodName) == _meals.end())
        _meals[foodName] = 1;
    else
        _meals[foodName] += 1;

}

int Chef::cookedNumber(std::string foodName)
{
    if (_meals.find(foodName) == _meals.end())
        return 0;
    else
        return _meals[foodName];
}

void Chef::introduce()
{
    std::cout << "Hi, my name is " << _name << ". I'm a chef with "
              << _experience << " points of experience and I know " << _meals.size() << " recipes." << std::endl;
}

std::string Chef::getFavoriteFood()
{   std::string favorite;
    if (_meals.empty()) {
        return "nothing";
    } else {
        std::vector<std::pair<std::string, int>> foods;
        std::copy(_meals.begin(), _meals.end(), std::back_inserter(foods)); // it makes the "_meals" map values into the foods vector


        int counter = 0;

        for (int i = 0; i < foods.size(); ++i) { // find the greatest number value
            if (foods.at(i).second > counter)
                 counter = foods.at(i).second;
        }

        for (int j = 0; j < foods.size(); ++j) { // make to a string all the foods which has the biggest integer value
            if (foods.at(j).second == counter){
                if (favorite.empty())
                    favorite = foods.at(j).first;
                else
                    favorite += " and " + foods.at(j).first;
            }
        }
    }
    return favorite;
}