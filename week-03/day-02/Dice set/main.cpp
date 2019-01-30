#include <iostream>

#include "dice_set.h"

int main(int argc, char* args[])
{
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6
    DiceSet diceSet;
    diceSet.roll();

    int six_num = 0; //number of six

    for (int i = 0; i < 6; i++){ // check the first roll, how many six in it
        if (diceSet.getCurrent(i) == 6){
            six_num += 1;
        }
    }

    if (six_num == 6) { //if the first
        for (int i = 0; i < 6; i++) {
            std::cout << diceSet.getCurrent(i) << " ";
        }
    }


   while (six_num != 6) {//goes until every dice value is six
        int dice_number = 0; // dice counter
        while (dice_number != 6) {//reroll the not six dice
            if (diceSet.getCurrent(dice_number) != 6) {
                diceSet.roll(dice_number);
                if (diceSet.getCurrent(dice_number) == 6) {
                    six_num++;
                }
            }
            dice_number++;
        }
        for (int i = 0; i < 6; i++) { //write out the dice
            std::cout << diceSet.getCurrent(i) << " ";
        }
            std::cout << std::endl;
        }

    return 0;
}