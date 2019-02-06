//
// Created by bolar on 2019. 02. 06..
//

#ifndef WIRELESS_ADAPTER_DEVICE_H
#define WIRELESS_ADAPTER_DEVICE_H
#include <iostream>

class Device {
public:
    Device(std::string id);
    std::string getID();
protected:
    std::string _id;
};


#endif //WIRELESS_ADAPTER_DEVICE_H
