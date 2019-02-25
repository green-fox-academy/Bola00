#include <stdio.h>
#include <stdlib.h>
// Create a program which asks for a number and stores it
// Create a function which takes a number as a parameter and
// returns 1 if that number is even and returns 0 otherwise
// (in this case 0 is an even number)

int oddOrEven(int numb)
{
    return numb % 2 == 0;
}

int main()
{
    int userInput;
    printf("give me number!");
    scanf("%d", &userInput);

    printf("%d", oddOrEven(userInput));
    return 0;
}