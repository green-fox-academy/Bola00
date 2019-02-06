//
// Created by bolar on 2019. 02. 06..
//

#ifndef WIRELESS_ADAPTER_NETWORKDEVICE_H
#define WIRELESS_ADAPTER_NETWORKDEVICE_H
#include "Device.h"

class NetworkDevice : virtual public Device
{
public:
    NetworkDevice(std::string id, int bandwith);
protected:
    int _bandwidth;
};


#endif //WIRELESS_ADAPTER_NETWORKDEVICE_H
