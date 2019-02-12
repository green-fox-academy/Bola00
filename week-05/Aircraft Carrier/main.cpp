#include <iostream>
#include "aircraft.h"
#include "F16.h"
#include "F35.h"
#include "Carrier.h"


int main() {
    F16 One;
    F16 Two;
    F35 Three;
    F35 Four;

    Carrier carrierone (200, 3000);
    carrierone.add(&One);
    carrierone.add(&Two);
    carrierone.add(&Three);
    carrierone.add(&Four);

std::cout << carrierone.getStatus() << std::endl;

carrierone.fill();

std::cout << carrierone.getStatus() << std::endl;
Carrier carriertwo(10, 100);
std::cout << carriertwo.getStatus() << std::endl;
carrierone.fight(carriertwo);
std::cout << carriertwo.getStatus() << std::endl;
    return 0;
}