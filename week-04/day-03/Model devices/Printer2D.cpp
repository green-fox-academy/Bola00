//
// Created by bolar on 2019. 02. 06..
//

#include "Printer2D.h"
Printer2D::Printer2D(int sizeX, int sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
}

std::string Printer2D::getSize()
{

    std::cout <<_sizeX << " + X + " << _sizeY << std::endl;
}

