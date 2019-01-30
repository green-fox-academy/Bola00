#ifndef DOMINOES_DOMINO_H
#define DOMINOES_DOMINO_H

#include <iostream>
#include <utility>

class Domino
{
public:
    Domino(int valueA, int valueB); //makes the vector elements to pairs

    std::pair<int,int> getValues(); // give the current domino"s value
    std::string toString(); //write aout the current domino

private:
    std::pair<int,int> _values;
};


#endif //DOMINOES_DOMINO_H