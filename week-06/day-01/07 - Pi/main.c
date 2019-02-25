
#include <stdio.h>
#include <stdlib.h>
#include "circle.h"


// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

//08 - Create another function which calculates the circumference of a circle
//circumference = 2 * radius * PI

int main()
{

    int radius = 3;

    printf("%.2f\n", area(radius));
    printf("%.2f", circumference(radius));

    return 0;
}