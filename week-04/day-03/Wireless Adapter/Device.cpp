//
// Created by bolar on 2019. 02. 06..
//

#include "Device.h"
Device::Device(std::string id)
{
    _id = id;
}

std::string Device::getID()
{
    return _id;
}