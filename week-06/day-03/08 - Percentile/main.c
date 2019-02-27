#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int percent_calculator(int array[], int longness, int percentage)
{
    int sum = 0;
    for(int i = 0; i < longness; i++)
    {
        sum += array[i];
    }

    return sum / 100 * percentage;
}

int main()
{
    int numbercounter;
    printf("How many numbers do you want?");
    scanf("%d", &numbercounter);

    int *numbers = NULL;
    numbers = (int *) malloc(numbercounter * (sizeof(int)));

    for (int i = 0; i < numbercounter; ++i) {
        printf("Number %i: ", i + 1);
        scanf("%i", &numbers[i]);
    }

    printf("%d\n",percent_calculator(numbers, numbercounter, 80));
    printf("%d\n",percent_calculator(numbers, numbercounter, 90));

    free(numbers);
    return 0;
}