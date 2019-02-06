//
// Created by bolar on 2019. 02. 06..
//

#include "Scanner.h"

Scanner::Scanner(int speed)
{
 _speed = speed;
}

void Scanner::scan()
{
  std::cout <<"I'm scanning a document" << _speed <<" ppm" << std::endl;
}