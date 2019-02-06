#include <iostream>
#include "Animals.h"
#include "Bird.h"
#include "flyable.h"
#include "Vehicle.h"
#include "Helicopter.h"


int main() {

    Bird bird("Sas");

    bird.fly();
    bird.takeOff();
    bird.fly();
    bird.land();

    Helicopter helicopter;
    helicopter.fly();
    helicopter.takeOff();
    helicopter.fly();
    helicopter.land();

    return 0;
}