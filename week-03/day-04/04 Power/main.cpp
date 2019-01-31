#include <iostream>

// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).

int powerN (int base, int n){
    if (n == 1){
        return base;
    } else {
        return (base * powerN(base, n-1));
    }

}

int main() {

    int baseNumber;
    int power;

    std:: cout << "Give me a number: ";
    std::cin >> baseNumber;
    std:: cout << "power: ";
    std::cin >> power;

    std:: cout << powerN (baseNumber, power);

    return 0;
}