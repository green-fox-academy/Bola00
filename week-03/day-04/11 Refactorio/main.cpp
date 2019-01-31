#include <iostream>

// Create a recursive function called `refactorio`
// that returns it's input's factorial

int refactorio(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return (n * refactorio(n-1));
    }
}
int main() {

    int userInput;

    std::cout <<"Number: ";
    std::cin >> userInput;

    std::cout << refactorio(userInput);
    return 0;
}