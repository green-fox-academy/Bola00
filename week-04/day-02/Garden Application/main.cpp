#include <iostream>
#include "garden.h"
#include "flower.h"
#include "tree.h"

int main() {

    Garden garden("BigGarden");
    Flower flowerOne ("yellow Flower");
    Flower flowerTwo ("blue Flower");
    Tree treeOne ("purple Tree");
    Tree treeTwo ("orange Tree");

    garden.addPlant(&flowerOne);
    garden.addPlant(&flowerTwo);
    garden.addPlant(&treeOne);
    garden.addPlant(&treeTwo);
    garden.watering(40);
    std::cout << std::endl;
    garden.watering(70);



    return 0;
}