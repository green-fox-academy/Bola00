//
// Created by bolar on 2019. 02. 06..
//

#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
#include <iostream>
#include "instrument.h"
#include "stringedInstrument.h"

class Violin : public StringedInstrument
{
public:
    Violin ();
    Violin(int strings);
    std::string sound();

};


#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
