//
// Created by bolar on 2019. 02. 06..
//

#include "bassGuitar.h"

BassGuitar::BassGuitar()
{
    name = "Base Guitar";
    numberOfStrings = 4;

}

BassGuitar::BassGuitar(int strings)
{
    name = "Base Guitar";
    numberOfStrings = strings;

}

std::string BassGuitar::sound()
{
    return "Duum-duum-duum";
}


