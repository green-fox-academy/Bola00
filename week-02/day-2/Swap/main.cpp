#include <iostream>

//it change the the values of the memory addresses
void swap ( int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main () {
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;

    // add the memory addresses to the swap funtion
    swap(&a, &b);

    std::cout << a << " " << b;
    return 0;
}