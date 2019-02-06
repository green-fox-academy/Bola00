#include <iostream>
#include "Device.h"
#include "USBDevice.h"
#include "NetworkDevice.h"
#include "WirelessAdapter.h"


int main() {

        WirelessAdapter adapter("da4c32fb21", USBType::USB_TYPE_2, 100);
        adapter.info();

    return 0;
}