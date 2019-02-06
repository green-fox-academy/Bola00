//
// Created by bolar on 2019. 02. 06..
//

#ifndef MODEL_DEVICES_SCANNER_H
#define MODEL_DEVICES_SCANNER_H
#include <iostream>

class Scanner {
public:
    Scanner(int speed);
    void   scan();
private:
    int _speed;
};




#endif //MODEL_DEVICES_SCANNER_H
