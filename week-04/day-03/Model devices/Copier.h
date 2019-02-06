//
// Created by bolar on 2019. 02. 06..
//

#ifndef MODEL_DEVICES_COPIER_H
#define MODEL_DEVICES_COPIER_H
#include "Scanner.h"
#include "Printer2D.h"
#include <iostream>


class Copier : public Printer2D, public Scanner
{
public:
    Copier(int sizeX, int sizeY, int seed);
    void copy();
};


#endif //MODEL_DEVICES_COPIER_H
