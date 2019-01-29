#ifndef FLEET_OF_THINGS_THING_H
#define FLEET_OF_THINGS_THING_H

#include <string>

class Thing
{
public:
    Thing(const std::string& name); //gets te lists and false

    void complete(); //it make the stuff complete
    std::string toString();// make the two information in to i string

private:
    std::string _name;
    bool _completed;
};


#endif //FLEET_OF_THINGS_THING_H