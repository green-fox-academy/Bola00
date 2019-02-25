#include <stdio.h>
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the reminder of 22 divided by 13

    // Store the results in variables and use them when you display the result

int main()
{

    int sum = 13 + 22;
    int sub = 22 - 13;
    int multi = 22 * 13;
    double divided = (double) 22 / 13;
    int reminder = 22 % 13;

    printf("%d, %d, %d, %.1f, %d", sum, sub, multi, divided, reminder);
    return 0;
}