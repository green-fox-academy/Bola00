#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    int stringLenght(char name[])
    {
        return strlen(name);
    }

int main()
{
    char userInput[20];
    printf("give me your name!");
    gets(userInput);

    printf("%d", stringLenght(userInput));

    return 0;
}