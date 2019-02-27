#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char* concatenate (char string1[], char string2[])
{
    int string_long = strlen(string1) + strlen(string2);
    char* new_word = (char*)malloc(string_long * sizeof(char));

    int indexcounter = 0;
    for (int i = 0; i < strlen(string1); i++) {
        new_word[indexcounter] = string1[i];
        indexcounter++;
    }

    for (int i = 0; i < strlen(string2); i++) {
        new_word[indexcounter] = string2[i];
        indexcounter++;
    }
    
    return new_word;
}

int main()
{

    char word1[] = "alma";
    char word2[] = "csutka";

     char* result = concatenate(word1, word2);

     printf("%s", result);

     free(result);
    return 0;
}