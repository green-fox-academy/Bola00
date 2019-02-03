#include <iostream>
// Write a program that asks for a number.
// It would ask this many times to enter an integer,
// if all the integers are entered, it should print the sum and average of these
// integers like:
//
// Sum: 22, Average: 4.4

int main() {
    int counter = 0;
    int sum = 0;

        while (1) {
            int userInput;
            std::cout << "Number: ";
            std::cin >> userInput;
            if (std::cin.fail()){
              goto badInput;
            }else {
                sum += userInput;
                counter++;
                std::cout << "Sum: " << sum << ", Average: " << (double) sum / counter << std::endl;
            }
        }
       badInput:
        std::cout << "It's not good!" << std::endl;
    return 0;
}