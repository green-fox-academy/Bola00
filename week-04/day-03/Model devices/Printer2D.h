//
// Created by bolar on 2019. 02. 06..
//

#ifndef MODEL_DEVICES_PRINTER2D_H
#define MODEL_DEVICES_PRINTER2D_H
#include <iostream>
#include "Printer.h"

class Printer2D : public Printer
{
public:
    Printer2D(int sizeX, int sizeY);
    std::string getSize() override;

protected:
    int _sizeX;
    int _sizeY;
};


#endif //MODEL_DEVICES_PRINTER2D_H
