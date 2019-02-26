#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char *word)
{
    char checker = 'g';
    int counter = 0;
    int findTheFirst = 0;

    while (word[findTheFirst] != checker)
        findTheFirst++;

    for (int i = findTheFirst + 1; i < strlen(word); i++) {
        if (word[i] == checker)
            break;
        else
            counter++;
    }

    return counter;
}

main()
{

    char *word = "Programming";

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d", count_between_chars(word));

    return 0;
}
// Create a function which takes a string as a parameter and
// returns the number of characters between two repeating characters
// the repeating char can be a local variable in the function itself or
// it can be passed to the function as parameter