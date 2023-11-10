#ifndef _9M_DC6653F1_7134_6473_ABF9_D3621CEB50E5
#define _9M_DC6653F1_7134_6473_ABF9_D3621CEB50E5

#pragma once
#include <Windows.h>

enum PosPrinterUsbEvent
{
    /// A device has been plugged in and is ready to use
    PPU_EVENT_DEVICE_ARRIVED = 0x01,

    /// A device has left and is no longer available.
    /// It is the user's responsibility to call libusb.close on any handle associated
    /// with a disconnected device.
    /// It is safe to call libusb.get_device_descriptor on a device that has left
    PPU_EVENT_DEVICE_LEFT,
};

class PosPrinterUsbHotplug
{
public:
    PosPrinterUsbHotplug();
    virtual ~PosPrinterUsbHotplug();
    virtual void start();
    virtual void stop();
    bool isStarted();

protected:
    virtual void onEvent(PosPrinterUsbEvent evt);

private:
    friend class PosPrinterUsbHotplugPrivate;
    class PosPrinterUsbHotplugPrivate* dPtr_;
};

#endif /* _9M_DC6653F1_7134_6473_ABF9_D3621CEB50E5 */
