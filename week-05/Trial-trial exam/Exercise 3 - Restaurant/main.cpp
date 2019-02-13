#include <iostream>
#include "restaurant.h"
#include "employees.h"
#include "waiter.h"
#include "chef.h"
#include "manager.h"
int main()
{

Chef chef ("John", 3);

chef.work();
std::cout << chef.getFavoriteFood() << std::endl;
std::cout << chef.cookedNumber("pacal") << std::endl;
chef.work();
chef.work();
chef.cook("pacal");
chef.cook("pacal");
chef.cook("barack");
chef.cook("gombaleves");
chef.cook("gombaleves");
chef.introduce();
std::cout << chef.getFavoriteFood() << std::endl;

Manager manager ("Judit", 5);
Waiter waiter("Kristof");

Restaurant restaurant("Maybe", 2017);
restaurant.hire(&chef);
restaurant.hire(&manager);
restaurant.hire(&waiter);

restaurant.guestsArrived();
restaurant.guestsArrived();
chef.cook("money");
chef.cook("tej");
std::cout << std::endl;

restaurant.everybodyIntroduce();

    return 0;
}