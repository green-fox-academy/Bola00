
#include <stdio.h>
#include <stdlib.h>

int areEqual(int num1, int num2)
{
    return num1 == num2;
}

int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int num1;
    int num2;
    printf("give me two number. \n Number 1:");
    scanf("%d", &num1);
    printf("Number 2:");
    scanf("%d", &num2);

    printf("%d", areEqual(num1, num2));
    return 0;
}