#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ctype.h> tolower(str[i]) -> this is an easier solution !


// Create a program which asks for two strings and stores them
// Create a function which takes two strings as parameters and
// returns 1 if the two strings are the same and 0 otherwise
// Try to erase small and uppercase sensitivity.

int sameStringsChecker(char string1[], char string2[])
{
    int lengOfFirst = strlen(string1);
    int lengOfSecond = strlen(string2);

    if (lengOfFirst != lengOfSecond)
        return 0;

    for (int i = 0; i < lengOfFirst; i++) {
        if (string1[i] >= 'A' && string1[i] <= 'Z')
            string1[i] += 32;

        if (string2[i] >= 'A' && string2[i] <= 'Z')
            string2[i] += 32;

        if (string1[i] != string2[i])
            return 0;
    }

    return 1;
}

main()
{
    char userInput[20];
    printf("give me a word: ");
    gets(userInput);
    char userInput2[20];
    printf("and another: ");
    gets(userInput2);

    printf("\n%d", sameStringsChecker(userInput, userInput2));
    return 0;
}