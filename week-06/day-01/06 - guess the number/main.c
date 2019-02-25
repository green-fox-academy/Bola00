#include <stdio.h>
// Write a program that stores a number, and the user has to figure it out.
// The user can input guesses, after each guess the program would tell one
// of the following:
//
// The stored number is higher
// The stried number is lower
// You found the number: 8
int main()
{
    int myNumber = 12;

    for ( ; ; ) {
        int guessNumber;
        printf("Guess a number!\n");
        scanf("%d", &guessNumber);

        if (guessNumber > myNumber) {
            printf("The stored number is lower\n");

        } else if (guessNumber < myNumber) {
            printf("The stored number is higher\n");
        } else {
            printf("You found the number: %d", myNumber);

            return 0;
        }

    }

}
