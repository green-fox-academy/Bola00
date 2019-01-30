#ifndef DICE_SET_DICE_SET_H
#define DICE_SET_DICE_SET_H

#include <iostream>
#include <vector>

class DiceSet
{
public:

    DiceSet(); //random in time and make a 6 places vector

    void roll(); //roll with 6 dice
    void roll(int i); // reroll the numbered dice
    std::vector<int> getCurrent() const; // show the vector of dices
    int getCurrent(int i) const; // show a specific dice
private:
    std::vector<int> dices;
};


#endif //DICE_SET_DICE_SET_H