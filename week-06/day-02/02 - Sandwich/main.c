#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct
{
  char* name;
  float price;
  float weight;
} sandwich;

float order(sandwich sando, int numberOfsando)
{
    return sando.price * numberOfsando;
}

int main()
{
    sandwich cheese;
    cheese.name = "Cheeslover";
    cheese.price = 2.71;

    printf("%.3f",order(cheese, 4));


    return 0;
}