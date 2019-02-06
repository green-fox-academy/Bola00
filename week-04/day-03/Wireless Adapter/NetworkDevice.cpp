//
// Created by bolar on 2019. 02. 06..
//

#include "NetworkDevice.h"
NetworkDevice::NetworkDevice(std::string id, int bandwith)
: Device (id)
{
    _bandwidth = bandwith;
}