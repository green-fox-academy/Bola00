#include <stdio.h>
#include <stdlib.h>
// Create a program which asks for a number and stores it
// Create a function which takes a number as a parameter
// and returns 1 if the number is a prime number and 0 otherwise
// (in this case 0 is not considered as a prime number)

int primeCheckker(int number)
{
    if (number <= 1)
        return 0;
for (int i = 2; i <number; i++){
    if(number % i == 0)
        return 0;
}
    return 1;
}
int main()
{
    int userInput;
    printf("give me number!");
    scanf("%d", &userInput);

    printf("%d", primeCheckker(userInput));
    return 0;
}