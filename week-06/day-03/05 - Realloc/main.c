
#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* usernumbers = NULL;
    int number_of_numbers;

    printf("How many number do you want?");
    scanf("%i", &number_of_numbers);

    usernumbers = (int*)malloc(number_of_numbers * sizeof(int)); //user decide the long of the array

    printf("Start to give the numbers!");

    int sum_usernumbers = 0;
    for (int i = 0; i < number_of_numbers; ++i) { // give the numbers
        printf("Number %d: ", i+1);
        scanf("%d", &usernumbers[i]);
        sum_usernumbers += usernumbers[i];
    }


    int* ones_from_sum = NULL;
    ones_from_sum = (int*)malloc(sum_usernumbers * sizeof(int));
    for (int i = 0; i < sum_usernumbers; i++){
        ones_from_sum[i] = 1;
    }

    for (int j = 0; j < sum_usernumbers; ++j) {
        printf("%i: %i\n", j+1, ones_from_sum[j]);
    }

    free(usernumbers);
    free(ones_from_sum);
    return 0;
}