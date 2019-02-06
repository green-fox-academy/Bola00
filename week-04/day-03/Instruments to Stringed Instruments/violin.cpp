//
// Created by bolar on 2019. 02. 06..
//

#include "violin.h"

Violin::Violin()
{
    name = "Violin";
    numberOfStrings = 4;

}

Violin::Violin(int strings)
{
    name = "Violin";
    numberOfStrings = strings;

}

std::string Violin::sound()
{

    return "Screech";
}

