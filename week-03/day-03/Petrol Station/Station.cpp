//
// Created by bolar on 2019. 01. 30..
//

#include "Station.h"
#include "Cars.h"

Station::Station() {
    Sgas_amount = 500;
}

std::string Station::fill(Cars &car) {
   Sgas_amount--;
   car.fill();
   if (Sgas_amount == 0){
       throw 0;
   }
   if ( !car.isFull() ){
      return "Filling the car! \n";
   }
    if ( car.isFull() ){
        return "The gas station has " + std::to_string(Sgas_amount) + " gas.";
    }
}