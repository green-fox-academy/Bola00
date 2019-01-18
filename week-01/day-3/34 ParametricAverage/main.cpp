#include <iostream>

void sas(int x, int& q){
    q += x;}


int main() {
    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    int b =0;
    for(int i =1; ; i++){
        int a[i];
        std::cout<<"Give me a number: ";
        std::cin>>a[i];


        sas(a[i], b);

        std::cout<<"sum: " << b << ", Average: " << (float)b /i <<std::endl;

    }


    return 0;
}