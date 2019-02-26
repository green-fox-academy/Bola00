#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/


typedef struct
{
  float x;
  float y;
} point_t;

point_t create_point(float num1, float num2)
{
    point_t temp;
    temp.x = num1;
    temp.y = num2;
    return temp;
}

float distance(point_t point1, point_t point2)
{
    float x1;
    float x2;
    float y1;
    float y2;

    if (point1.x < point2.x) {
        x2 = point2.x;
        x1 = point1.x;
    } else {
        x2 = point1.x;
        x1 = point2.x;
    }

    if (point1.y < point2.y) {
        y2 = point2.y;
        y1 = point1.y;
    } else {
        y2 = point1.y;
        y1 = point2.y;
    }

    // stuff above is important for the correct use of Pythagorean theorem
    float temp = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1); //Pythagorean theorem
    float distance = (float) sqrt(temp); //sqrt -> gyökvonás

    return distance;

}

int main()
{

    point_t p1 = create_point(1, 1);
    point_t p2 = create_point(1, 5.5);
    float dist = distance(p1, p2);
    printf("%f", dist);

    return 0;
}