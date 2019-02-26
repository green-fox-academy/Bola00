#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type
{
  VOLVO, TOYOTA, LAND_ROVER, TESLA
};

struct car
{
  enum car_type type;
  double km;
  double gas;
};

void car_parameters(struct car car1)
{
    char *cartype;
    if (car1.type == 0)
        cartype = "VOLVO";
    else if (car1.type == 1)
        cartype = "TOYOTA";
    else if (car1.type == 2)
        cartype = "LAND_ROVER";
    else if (car1.type == 3)
        cartype = "TESLA";

    if (cartype == "TESLA")
        printf("car type: %s, km: %.2f \n", cartype, car1.km);
    else
        printf("car type: %s, km: %.2f, gas: %.2f \n", cartype, car1.km, car1.gas);
}

int main()
{
    struct car car1;
    car1.type = 1;
    car1.gas = 13;
    car1.km = 300;

    struct car car2;
    car2.type = 3;
    car2.km = 130;
    car2.gas = 0;
    car_parameters(car1);
    car_parameters(car2);

    return 0;
}