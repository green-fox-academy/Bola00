#include <iostream>
#include <vector>

#include "domino.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...

    int current_dom_num = 0; // the actual domino's index
    for ( int i = 0; i < dominoes.size(); i++) // goes on the dominoes
    {
        std::cout << dominoes.at(current_dom_num).toString(); //print the current domino

        int domino_count = 0; //countint the domino's index
        while (dominoes.at(current_dom_num).getValues().second != dominoes.at(domino_count).getValues().first)
        //check which domino's has the the same amount for first value as the current domino's second
        {
            domino_count ++;
        }
        current_dom_num = domino_count;

    }

    return 0;
}