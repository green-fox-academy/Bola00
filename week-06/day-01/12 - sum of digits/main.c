#include <stdio.h>
// Create a program which asks for two numbers and stores them
// Create a function which takes two numbers as parameters
// and returns 1 if the sum of the number of digits are equal and 0 otherwise

int digitsAreEqual(int num1, int num2)
{
    int sumNum1 = 0;
    int sumNum2 = 0;

    while(num1 != 0 || num2 != 0){
        sumNum1 += num1 % 10;
        sumNum2 += num2 % 10;

        num1 /= 10;
        num2 /= 10;
    }
    return sumNum1 == sumNum2;
}
int main()
{
    int userInput1;
    int userInput2;
    printf("give me number!");
    scanf("%d", &userInput1);
    printf("One more!");
    scanf("%d", &userInput2);

    printf("%d", digitsAreEqual(userInput1,userInput2));

    return 0;
}