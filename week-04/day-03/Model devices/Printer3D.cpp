//
// Created by bolar on 2019. 02. 06..
//

#include "Printer3D.h"

Printer3D::Printer3D(int sizeX, int sizeY, int sizeZ)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
    _sizeZ = sizeZ;

}

std::string Printer3D::getSize()
{
    std::cout <<_sizeX << " + X + " << _sizeY <<" + X + " << _sizeZ << std::endl;
}


