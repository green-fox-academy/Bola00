//
// Created by bolar on 2019. 02. 06..
//

#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
#include <iostream>
#include "instrument.h"
#include "stringedInstrument.h"

class BassGuitar : public StringedInstrument
{
public:
    BassGuitar ();
    BassGuitar(int strings);
    std::string sound();
};


#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
