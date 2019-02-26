#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subString(char *word1, char *word2)
{

    char *longer;
    char *shorter;
    if (strlen(word1) == strlen(word2))
        return -1;

    if (strlen(word1) > strlen(word2)) {
        longer = word1;
        shorter = word2;
    } else {
        longer = word2;
        shorter = word1;
    }

    for (int i = 0; i < strlen(longer); ++i) {
        int counter = 0;
        for (int j = 0; j <= strlen(shorter); ++j) {
            if (j == strlen(shorter) )
                return 1;
            else if(longer[i+j] == shorter[j])
                counter++;
            else
                break;
        }

    }
    return 0;

}

main()
{
    char input1[20];
    char input2[20];
    printf("A word please:");
    gets(input1);
    printf("Another word please:");
    gets(input2);

    printf("%i", subString(input1, input2));
    return 0;
}
// Create a program which asks for two strings and stores them
// Create a function which takes two strings as parameters and
// returns 1 if the shorter string is a substring of the longer one and
// returns 0 otherwise
// If the two strings has the same lenght than the function should return -1
