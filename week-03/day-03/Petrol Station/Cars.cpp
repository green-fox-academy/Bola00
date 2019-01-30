//
// Created by bolar on 2019. 01. 30..
//

#include "Cars.h"

Cars::Cars(int gas, int tank ){
    Cgas_amount = gas;
    capacity = tank;
}

bool Cars::isFull(){
    return (Cgas_amount == capacity);
}

void Cars::fill() {
    Cgas_amount++;
}


