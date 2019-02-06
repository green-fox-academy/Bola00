//
// Created by bolar on 2019. 02. 06..
//

#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
#include <iostream>
#include "instrument.h"
#include "stringedInstrument.h"

class ElectricGuitar : public StringedInstrument
{
public:
    ElectricGuitar ();
    ElectricGuitar(int strings);
    std::string sound();


};


#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
