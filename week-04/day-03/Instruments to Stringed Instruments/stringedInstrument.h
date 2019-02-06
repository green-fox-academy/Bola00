//
// Created by bolar on 2019. 02. 06..
//

#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
#include <iostream>
#include "instrument.h"

class StringedInstrument  : public Instrument
{
public:
    virtual std::string sound()=0;
    void play ();

protected:
    int numberOfStrings;


};


#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
