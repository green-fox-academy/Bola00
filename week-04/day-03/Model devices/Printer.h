//
// Created by bolar on 2019. 02. 06..
//

#ifndef MODEL_DEVICES_PRINTER_H
#define MODEL_DEVICES_PRINTER_H
#include <iostream>

class Printer
{
public:
   virtual std::string getSize()=0;
   void print();

};


#endif //MODEL_DEVICES_PRINTER_H
