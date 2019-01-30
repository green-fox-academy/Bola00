//
// Created by bolar on 2019. 01. 30..
//

#include "Farm.h"

Farm::Farm()
{
    slots = 3;

}

std::string Farm::breed ()
{
    if (farmanimals.size() == slots){
        return "No slots for more animals!";
    }else {
        Animal cow;
        farmanimals.push_back(cow);
        return "A new cow was born!";
    }
}
std::string Farm::slaughter()
{
 if (farmanimals.size() == 0)
 {
     return "You need animals first!";
 }else
     {
     int chosen_one = 0;

     for (int i = 1; i < farmanimals.size(); i++){
         if (farmanimals.at(chosen_one).hunger > farmanimals.at(i).hunger){
            chosen_one = i;
         }
     }
     farmanimals.erase(farmanimals.begin() + chosen_one);
     return " You killed one cow!";
    }

}