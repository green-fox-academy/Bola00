#include <iostream>
#include "Station.h"
#include "Cars.h"
//Create Station and Car classes
//
//Station
//
//Members:
//gasAmount
//create a constructor that initializes the gasAmount
//fill(car) -> fills 1 unit of gas until the car is on full. Every time it transfers 1 unit it should print "Filling car!" on the console. When the car is full it should print the remaining gas amount of the station
//Car
//
//Members:
//gasAmount
//capacity
//create constructor for Car with 2 arguments(gasAmount and capacity)
//car has 2 methods:
//isFull() -> returns true if capacity equals to gasAmount, false otherwise
//fill() -> increments the gasAmount by one.
//In the main function create a station and 5 cars with different amount of capacity and gas. Refill all the cars.
int main() {
    Station StarStation;

    Cars Mamacar(80, 99);
    Cars Johnstrash(40, 80);
    Cars Luxurycar(31, 150);
    Cars Bananacar(91, 100);
    Cars Policecar(20, 90);

   try {
       while (!Mamacar.isFull()) {
           std::cout << StarStation.fill(Mamacar);
       }
       while (!Luxurycar.isFull()) {
           std::cout << StarStation.fill(Luxurycar);
       }
       while (!Johnstrash.isFull()) {
           std::cout << StarStation.fill(Johnstrash);
       }
       while (!Bananacar.isFull()) {
           std::cout << StarStation.fill(Bananacar);
       }
       while (!Policecar.isFull()) {
           std::cout << StarStation.fill(Policecar);
       }
   }catch (int){
       std::cout << "the gas station is empty!";
   }

    return 0;
}