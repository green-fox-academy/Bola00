//
// Created by bolar on 2019. 01. 29..
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
    int value;
    int initial_value;
public:
    Counter(); //if there is no initial int, the value is 0;
    Counter(int number); //if there is initial int, the value is it;
    void add(); // if there is no int, add +1 to the value
    void add(int number);// if there is int, add int to the value
    int get();// get the actual value
    void reset();// it turn back the value to the initial
};


#endif //COUNTER_COUNTER_H
