#include <stdio.h>
// Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000
int main()
{
    int side1;
    int side2;
    int side3;
    printf("Give me a 3 number!\n Number1:");
    scanf("%d", &side1);
    printf("Number2:");
    scanf("%d", &side2);
    printf("Number3:");
    scanf("%d", &side3);

    printf("Surface Area: %d\n", (side1 + side2 + side3) );
    printf("Volume: %d", (side1 * side2 * side3) );;
    return 0;
}