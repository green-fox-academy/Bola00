//
// Created by bolar on 2019. 02. 06..
//

#ifndef WIRELESS_ADAPTER_WIRELESSADAPTER_H
#define WIRELESS_ADAPTER_WIRELESSADAPTER_H
#include "USBDevice.h"
#include "NetworkDevice.h"
#include <iostream>

class WirelessAdapter : public NetworkDevice, public USBDevice
{
public:
   WirelessAdapter(std::string id, USBType usbType, int bandw);
   void info();
};


#endif //WIRELESS_ADAPTER_WIRELESSADAPTER_H
