//
// Created by bolar on 2019. 02. 06..
//

#include "Copier.h"
void Copier::copy()
{
    scan();
    std::cout <<" and " << std::endl;
    print();
    std::cout << "." << std::endl;

}

Copier::Copier(int sizeX, int sizeY, int seed)
:Printer2D(sizeX, sizeY), Scanner(seed)
{}
