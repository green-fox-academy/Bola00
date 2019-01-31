#include <iostream>

// Write a recursive function that takes one parameter: n and counts down from n.

void counter (int n){
    std::cout << n << std::endl;
    n--;
    if (n >= 0) {
        counter(n);
    }
}

int main() {

    int userInput;
    std::cout <<"Number:";
    std::cin >> userInput;

    counter(userInput);



    return 0;
}