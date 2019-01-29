//
// Created by bolar on 2019. 01. 29..
//
#include <iostream>
#include "Counter.h"

Counter::Counter() {//if there is no initial int, the value is 0;
    value = 0;
    initial_value = 0;
}
Counter::Counter(int number) {//if there is initial int, the value is it;
    value = number;
    initial_value = number;
}
void Counter::add(){// if there is no int, add +1 to the value
    value++;
}
void Counter::add(int number){// if there is int, add int to the value
    value = number;
}
int Counter::get() {// get the actual value
    return value;
}
void Counter::reset(){// it turn back the value to the initial
    value = initial_value;
}