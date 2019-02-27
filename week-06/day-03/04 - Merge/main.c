#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int *pointer1 = NULL;
    int *pointer2 = NULL;

    pointer1 = (int *) malloc(10 * sizeof(int));
    pointer2 = (int *) malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        pointer1[i] = i * 2 + 2;
        pointer2[i] = i * 2 + 1;
    }

    for (int j = 0; j < 10; ++j) {
        pointer1[j] = pointer2 [j];
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n", pointer1[i]);
    }

    free(pointer1);
    free(pointer2);

    return 0;
}