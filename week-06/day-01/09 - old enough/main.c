#include <stdio.h>
#include <stdlib.h>
#define LEGALAGE(age) (age >= 18) // one way to solve task task

// Create a program which asks for the age of the user and stores it
// Create a function which takes that age as a parameter and returns if the user is
// old enough to buy himself alcohol in Hungary

int legalage(int age) // second way to solve the task
{
    return age >= 18;
}

int main()
{

    int age;
    printf("How old are you?");
    scanf("%d", &age);
    if (legalage(age))
        printf("you can drink alcohol");
    else
        printf("too young");

    printf("\n");

    if (LEGALAGE(age))
        printf("you can drink alcohol");
    else
        printf("too young");

    return 0;
}