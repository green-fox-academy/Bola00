#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char* concatenate (char string1[], int count)
{
    int string_long = strlen(string1) * 5;
    char* new_word = (char*)malloc(string_long * sizeof(char));

    int indexcounter = 0;
    for (int j = 0; j < count; j++){
    for (int i = 0; i < strlen(string1); i++) {
        new_word[indexcounter] = string1[i];
        indexcounter++;
    }
    }
    new_word[string_long] = '\0';
    return new_word;
}

int main()
{

    char word1[] = "alma";
    int counter = 5;
    char* result = concatenate(word1, counter);

    printf("%s", result);

    free(result);
    return 0;
}