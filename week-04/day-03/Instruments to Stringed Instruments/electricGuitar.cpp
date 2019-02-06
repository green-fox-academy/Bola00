//
// Created by bolar on 2019. 02. 06..
//

#include "electricGuitar.h"

ElectricGuitar::ElectricGuitar()
{
    name = "Electric Guitar";
    numberOfStrings = 6;
}

ElectricGuitar::ElectricGuitar(int strings)
{
    name = "Electric Guitar",
    numberOfStrings = strings;

}


std::string ElectricGuitar::sound()
{
    return "Twang";
}
