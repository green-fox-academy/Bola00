#include <iostream>

// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
int sumDigits (int n)
{
    if (n == 0) {
        return 0;
    } else {
        int lastDigit = n % 10;
        n /= 10;
        return (lastDigit + sumDigits(n) );
    }
}




int main() {

    int userInput;
    std::cout <<"Number: ";
    std::cin >> userInput;

    std:: cout << sumDigits(userInput);
    return 0;
}