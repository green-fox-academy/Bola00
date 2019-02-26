#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string


    char *appendA(char word[]){
        char extraA = 'a';
        strcat (word, &extraA);

        return word;
}

main()
{
    char userWord[20];
    printf("give me a word: ");
    scanf("%s",userWord);

printf("%s", appendA(userWord));
    return 0;
}