//
// Created by bolar on 2019. 02. 01..
//
#include "Pirate.h"
Pirate::Pirate()
{
    _drunknessLevel = 0;
    _status = "okay";
    _parrot = false;
}
void Pirate::drinkSomeRum()
{
    if (_status == "dead") {
        std::cout << "This pirate can't drink because he is dead." << std::endl;
    } else if (_status == "passed out") {
        std::cout <<"This pirate can't drink because he is passed out." << std::endl;
    } else {
        _drunknessLevel++;
    }
    if (_drunknessLevel > 5){
        _status = "passed out";
    }

}
void Pirate::howsItGoingMate()
{
    if (_drunknessLevel <= 4){
        std::cout <<"Pour me anudder!" << std::endl;
    }else if (_status == "passed out"){
        std::cout <<"This pirate is passed out." << std::endl;
    }else if (_status == "dead"){
        std::cout << " This pirate is dead." << std::endl;
    }
    else {
        std::cout <<  "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
        _status = "passed out";
    }
}
void Pirate::die()
{
    _status = "dead";
}
void Pirate::brawl(Pirate another)
{
    if (_status == "dead" || _status == "passed out") {
        std::cout <<"This pirate can't brawl." << std::endl;
    }
    else if (another._status == "dead" || another._status == "passed out" ){
        std::cout << "The other pirate can't brawl." << std::endl;
    }else {
        srand(time(NULL));
        int ending = (rand()% 3);
        if (ending == 0){
            _status = "dead";
            std::cout <<"The pirate died!" << std::endl;
        }else if (ending == 1){
            another._status = "dead";
            std::cout << "The other pirate died!" << std::endl;
        } else if (ending == 2){
            _status = "passed out";
            another._status = "passed out";
            std::cout << "The pirates are passed each other out!" << std::endl;
        }
    }
}

void Pirate::getParrot()
{
    if (_parrot) {
        std::cout<< "This pirate already has a parrot!" << std::endl;
    }
    else
        {
        _parrot = true;
        std::cout <<"A pirate got a parrot!" << std::endl;
        }
}

void Pirate::loseParrot()
{
    _parrot = false;

}
std::string Pirate::statusinfo()
{
    return _status;
}

int Pirate::getDrunkLevel()
{
    return _drunknessLevel;
}


bool Pirate::parrotStatus()
{
    return _parrot;
}

void Pirate::wakingUp()
{
    if (_status == "passed out") {
        _status = "okay";
        _drunknessLevel = 0;
    }
}

