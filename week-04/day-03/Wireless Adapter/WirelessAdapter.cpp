//
// Created by bolar on 2019. 02. 06..
//

#include "WirelessAdapter.h"

WirelessAdapter::WirelessAdapter(std::string id, USBType usbType, int bandw)
:Device(id), NetworkDevice(id, bandw), USBDevice(id, usbType)
{}


void WirelessAdapter::info()
{
    std::cout <<"ID: " << _id << ", USBType: " << getUsbType() << ", and bandwidth: " << _bandwidth << std::endl;
}