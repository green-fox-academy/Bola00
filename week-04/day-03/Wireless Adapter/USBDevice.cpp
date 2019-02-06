//
// Created by bolar on 2019. 02. 06..
//

#include "USBDevice.h"
USBDevice::USBDevice(std::string id, USBType usbType)
: Device(id)
{
_usbType = usbType;
}

std::string USBDevice::getUsbType()
{
    if (_usbType == USBType::USB_TYPE_2)
        return "USB_TYPE_2";
    else
        return "USB_TYPE_3";
}