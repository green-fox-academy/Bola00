#include <stdio.h>
#include <string.h>
/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef int bool;

typedef struct
{
  char address[20];
  int price;
  int rooms;
  int area;

}house;


bool is_it_worth (house house1)
{
    return house1.area * 400 >= house1.price;
}

int worth_house_counter(house house[3])
{
    int counter = 0;

    for (int i = 0; i < sizeof(house); ++i) {
        if (is_it_worth(house[i]))
            counter++;
    }
    return counter;
}

int main()
{


house house1;
    strcpy (house1.address, "Baka street 1.");
    house1.area = 45;
    house1.price = 160000;
    house1.rooms = 2;

    house house2;
    strcpy (house2.address, "Baka street 2.");
    house2.area = 25;
    house2.price = 120000;
    house2.rooms = 1;

    house house3;
    strcpy (house3.address, "Baka street 3.");
    house3.area = 80;
    house3.price = 30000;
    house3.rooms = 3;

    house houses[3] ={house1, house2, house3};

    printf("There is %i house on the street which are worth it.", worth_house_counter(houses));

    return 0;
}