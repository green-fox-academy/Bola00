//
// Created by bolar on 2019. 02. 06..
//

#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H
#include <iostream>

class Instrument
{
public:
    virtual void play()=0;

protected:
    std::string name;
};


#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H
