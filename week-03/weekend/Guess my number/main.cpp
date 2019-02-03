#include <iostream>
#include <time.h>
//Write a program where the program chooses a number between 1 and 100. The player is then asked to enter a guess.
// If the player guesses wrong, then the program gives feedback and ask to enter an other guess until the guess is correct.
//
//Make the range customizable (ask for it before starting the guessing).
//You can add lives. (optional)
int main() {
    srand(time(NULL));

    int MyNumber = rand() % 100 + 1;
    int Lives = 5;

    std::cout << "I have a number between 1 and 100. You have 5 lives to find it." << std::endl;


    for (int i = 0; i < 5; i++){
        int guess;
        std::cout << "Number: ";
        std::cin >> guess;

        if (guess == MyNumber){
            std::cout << "You find my number!" << std::endl;
            goto End;
        }else if (guess > MyNumber){
            Lives--;
            std::cout << "It's too high! You have:" <<Lives << "." << std::endl;
        }else if (guess < MyNumber){
            Lives--;
            std::cout << "It's too low! You have:" <<Lives << "." << std::endl;
        }
    }

    std:: cout << "Your lost all your lives! My number was: " << MyNumber;
    End:
    return 0;
}