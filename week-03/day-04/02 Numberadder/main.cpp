#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

int counter (int n) {
    if (n <= 1)
    {return 1;
    }
    else
    {
        return (n + counter(n-1));
    }

}

int main() {

    int userInput;
    std::cout <<"Number:";
    std::cin >> userInput;

std::cout << counter(userInput);


    return 0;
}