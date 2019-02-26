#include <string.h>
#include <stdio.h>
/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

enum transmission
{
  MANUAL,
  AUTOMATIC,
  CVT,
  SEMI_AUTOMATIC,
  DUAL_CLUTCH
};

struct car
{
  char manufacturer_name[256];
  float price;
  int year;
  enum transmission type_of_transmission;
};

int get_older_cars_than(struct car *array, int array_length, int age)
{
    int counter = 0;
    for (int i = 0; i < array_length; ++i) {
        if (2019 - array[i].year > age)
            counter++;
    }
    return counter;
}

int get_transmission_count(struct car *array, int array_length, enum transmission trnsm)
{
    int counter = 0;
    for (int i = 0; i < array_length; ++i) {
        if (array[i].type_of_transmission == trnsm)
            counter++;
    }
    return counter;
}

int main()
{
struct car cars[4];
    cars[0].year = 2018;
    cars[1].year = 1990;
    cars[2].year = 2007;
    cars[3].year = 2010;

    cars[0].type_of_transmission = MANUAL;
    cars[1].type_of_transmission = AUTOMATIC;
    cars[2].type_of_transmission = AUTOMATIC;
    cars[3].type_of_transmission = CVT;

    printf("%i\n", get_older_cars_than(cars, 4, 3));
    printf("%i\n", get_transmission_count(cars, 4, MANUAL));


    return 0;
}