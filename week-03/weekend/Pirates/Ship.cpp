//
// Created by bolar on 2019. 02. 01..
//

#include "Ship.h"

void Ship::fillShip()
{

    srand(time(NULL));
    int i = rand() % 10 +10;

    for (int u = 0; u < i; u++){
        piratesOfShip.push_back(Pirate());
    }
    Pirate Captain;
    Captain.getParrot();
    std:: cout << "The ship is filled whith pirates!" << std::endl;

}

int Ship::alivePirates()
{
    int counter = 0;

    if (Captain.statusinfo() != "dead"){
        counter++;
    }

    for (int i = 0; i < piratesOfShip.size(); i++){
    if (piratesOfShip.at(i).statusinfo() != "dead"){
        counter++;
    }
    }
    return counter;
}

void Ship::status()
{


    std::cout <<"Captain Status: " << Captain.statusinfo() << ". His  drunkenness Level is: " << Captain.getDrunkLevel()<<". Alive Pirates on the ship: " << alivePirates()<< "." << std::endl;
}
int Ship::calculateScore(){
    int point = 0;

    if (Captain.statusinfo() == "okay"){
       point += 5 - Captain.getDrunkLevel();
    }
    if (Captain.parrotStatus()){
        point++;
    }

    for (int i = 0; i < piratesOfShip.size(); ++i) {
        if (piratesOfShip.at(i).statusinfo() == "okay"){
            point++;
            if(piratesOfShip.at(i).parrotStatus()){
                point++;
            }
        }

    }
    return point;
}


void Ship::wakeUpPirate()
{
    for (int i = 0; i < piratesOfShip.size(); i++){
      if (piratesOfShip.at(i).parrotStatus() && piratesOfShip.at(i).statusinfo() == "passed out"){
          piratesOfShip.at(i).wakingUp();
          std::cout << "A pirate woke up!" <<std::endl;
      }

    }
    if (Captain.statusinfo() == "passed out" && Captain.parrotStatus() ){
        Captain.wakingUp();
        std::cout <<" A Captain woke up!" << std::endl;
    }
}

void Ship::losing()
{
    srand(time(NULL));

    int numOfDies = rand() % alivePirates();

    if (numOfDies == 0) { // if Captain is alone is 100 % that he's gonna die
        Captain.die();
    } else {
        for (int i = 0; i > numOfDies; i++) {
            int randomPlace = rand() % piratesOfShip.size();
            if (piratesOfShip.at(randomPlace).statusinfo() != "dead") {
                piratesOfShip.at(randomPlace).die();
            } else {
                i--;
            }

        }
    }
}

void Ship::wining()
{  srand(time(NULL));
    int numberOfRum = rand() % 35 + 10;

    try {
        while (numberOfRum != 0) {
        if (Captain.statusinfo() == "okay") {
            Captain.drinkSomeRum();
            numberOfRum--;
        }
        int drinking = 0;
        while (numberOfRum != 0 && drinking != piratesOfShip.size()) {
            if (piratesOfShip.at(drinking).statusinfo() == "okay") {
                piratesOfShip.at(drinking).drinkSomeRum();
                numberOfRum--;
            }
            drinking++;
        }
    }

    }catch (...){
          std::cout << "Everyone is drunk on the ship!" << std::endl;
    }
}

int Ship::loseParrots()
{
    int losersParrots = 0;

    if (Captain.parrotStatus()){
        Captain.loseParrot();
        losersParrots++;
    }
    for (int i = 0; i < piratesOfShip.size(); i++) {
        if (piratesOfShip.at(i).parrotStatus() ){
            piratesOfShip.at(i).loseParrot();
            losersParrots++;
        }
    }
    return losersParrots;
}

void Ship::winParrots(int parrots)
{   int temp = parrots;
        if (!Captain.parrotStatus()) {
            Captain.getParrot();
            temp--;
        }
        int pirates = 0;
        while (parrots != 0 && pirates != piratesOfShip.size()) {
            if ( !piratesOfShip.at(pirates).parrotStatus() && piratesOfShip.at(pirates).statusinfo() != "dead" ){
                piratesOfShip.at(pirates).getParrot();
                temp--;
            }
        pirates++;

        }
        if (temp > 0){
            std::cout << "Some parrots are flying away!" << std::endl;
        }
}

bool Ship::shipBattle(Ship otherShip)
{
    wakeUpPirate();
    otherShip.wakeUpPirate();

    if (calculateScore() < otherShip.calculateScore() ){
       otherShip.winParrots(loseParrots());
       losing();
       otherShip.wining();
        std:: cout << "DEFENDERS WINS!" << std::endl;
        return false;
    }
    else {
        winParrots(otherShip.loseParrots());
        otherShip.losing();
        wining();

        std:: cout << "ATTACKERS WINS!" << std::endl;
        return true;
    }

}
