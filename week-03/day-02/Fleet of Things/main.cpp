
#include <iostream>

#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

Thing thing_one("Get milk"); // give stuff to the thing list
Thing thing_two("Remove the obstacles");
Thing thing_three("Stand up");
Thing thing_four ("Eat lunch");


thing_three.complete(); // make it complete
thing_four.complete();

fleet.add(thing_one); // add to the fleet list
fleet.add(thing_two);
fleet.add(thing_three);
fleet.add(thing_four);


    std::cout << fleet.toString() << std::endl;
    return 0;
}