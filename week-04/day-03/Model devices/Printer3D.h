//
// Created by bolar on 2019. 02. 06..
//

#ifndef MODEL_DEVICES_PRINTER3D_H
#define MODEL_DEVICES_PRINTER3D_H
#include "Printer.h"
#include <iostream>

class Printer3D : public Printer
{
public:
Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize() override;
private:
    int _sizeX;
    int _sizeY;
    int _sizeZ;

};


#endif //MODEL_DEVICES_PRINTER3D_H
