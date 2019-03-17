#include <stdio.h>
#include <string.h>
typedef enum{
  MANUAL,
  AUTOMATIC,
  CVT,
  SEMI_AUTOMATIC,
  DUAL_CLUTCH,
}transmission_t;

typedef struct{
  char manufactor [257];
  float price;
  int year;
  transmission_t transmission;
}car_t;

int get_cars_older_than(car_t* cars, int array_length, int age){
    int counter = 0;

    for (int i = 0; i < array_length; i ++) {
        if (2019 - cars[i].year > age)
            counter++;
    }
    return counter;
}

int get_transmission_count(car_t* cars, int array_length, transmission_t transmission){
    int counter = 0;
    for (int i = 0; i < array_length; i++){
        if (cars[i].transmission == transmission)
            counter++;
    }
    return counter;
}

int main()
{
    car_t one;
    car_t two;
    car_t three;
    strcpy(one.manufactor, "SUZUKI");
    strcpy(two.manufactor, "SUZUKI");
    strcpy(three.manufactor, "SUZUKI");
    one.year = 1989;
    two.year = 1999;
    three.year = 2012;
    one.price = 90;
    two.price = 120;
    three.price = 200;
    one.transmission = CVT;
    two.transmission = MANUAL;
    three.transmission = SEMI_AUTOMATIC;

    car_t arr[] = {one, two, three};

   printf("%d\n", get_cars_older_than(arr, 3, 18));
    printf("%d\n", get_transmission_count(arr, 3, SEMI_AUTOMATIC));
    return 0;
}