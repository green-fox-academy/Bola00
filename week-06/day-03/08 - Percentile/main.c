#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

float percent_calculator(int *array[], int longness[2], int percentage)
{
    int sum = 0;
    for (int i = 0; i < longness[0]; i++) {
        for (int j = 0; j < longness[1]; j++) {
            printf("%d, ",array[i][j]);
            sum += array[i][j];

        }
        printf("\n");
    }

    return (float) sum / 100 * percentage;
}

int main()
{

    int numbercounter[2];

    printf("How many lines do you want?");
    scanf("%d", &numbercounter[0]);
    printf("How many numbers in the lines do you want?");
    scanf("%d", &numbercounter[1]);

    int* numbers[numbercounter[0]];

    for (int j = 0; j < numbercounter[0]; j++) {
        numbers[j] = (int *) calloc(numbercounter[1], sizeof(int));
    }

    /* int *numbers = NULL;
     numbers = (int*) malloc(numbercounter[0] * numbercounter[1] * (sizeof(int)));
 */
    int counter = 1;
    for (int j = 0; j < numbercounter[0]; ++j) {
        for (int i = 0; i < numbercounter[1]; ++i) {
            printf("Number %d: ", counter);
            scanf("%i", &numbers[j][i]);
            counter++;
        }
    }

    printf("%.1f\n", percent_calculator(numbers, numbercounter, 80));
    printf("%.1f\n", percent_calculator(numbers, numbercounter, 90));

    for (int k = 0; k < numbercounter[0]; ++k) {
        free(numbers[k]);

    }

    return 0;
}