#include <iostream>

int main() {
    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4


    int num[5];

    std::cout<<"Give me 5 numbers and I tell yo they sum and they average!" <<std::endl;
    for (int i = 0; i<5; i++){
        std::cout<<"Number "<<i+1<<":";
        std::cin >>num[i];
    }

    double x;
    for (int i = 0; i<5; i++){
        x += num[i];
    }
    std::cout<<"Your numbers sum is " << x <<" and the average is " <<x/5 <<"." <<std::endl;
    return 0;
}