//
// Created by bolar on 2019. 02. 03..
//

#include "Armada.h"

Armada::Armada() {
    srand(time(NULL));
    int u = rand() % 4 +2;

    for (int i = 0; i < u; i ++){
    ships.push_back( Ship ());
    ships.at(i).fillShip();

    }
    std::cout << "This armada has " << ships.size() << " ships." << std::endl;
    system("pause");
}

bool Armada::armadaWar(Armada other_armada) {
    int attacker = 0;
    int defender = 0;

    while (attacker != ships.size() && defender != other_armada.ships.size()){
        if(ships.at(attacker).shipBattle(other_armada.ships.at(defender) )  ){
            defender++;
        }
        else {
            attacker++;
        }
    }
    if (attacker == ships.size()){
        std::cout << "Defender Armada wins!" << std::endl;
        return false;
    }
    else if (defender == other_armada.ships.size()){ //it shows it's always true, but it has not right!
        std::cout << "Attacker Armada Wins!" << std::endl;
        return true;
    }



}