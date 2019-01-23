#include <iostream>
#include <fstream>

void divides (int num){
    double result = 10 / num;
    std::cout << result ;
}

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    int a;
    std::cout << "number: ";
    std::cin >> a,

    divides (a);
    return 0;
}