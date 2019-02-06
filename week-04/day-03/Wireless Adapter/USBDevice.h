//
// Created by bolar on 2019. 02. 06..
//

#ifndef WIRELESS_ADAPTER_USBDEVICE_H
#define WIRELESS_ADAPTER_USBDEVICE_H
#include "Device.h"

enum class USBType{
    USB_TYPE_2,
    USB_TYPE_3
};

class USBDevice : virtual public Device
{
public:
    std::string getUsbType();
    USBDevice(std::string id, USBType);
protected:
    USBType _usbType;
};


#endif //WIRELESS_ADAPTER_USBDEVICE_H
