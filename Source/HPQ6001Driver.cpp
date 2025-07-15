#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/acpi/IOACPIPlatformDevice.h>
#include "HPQ6001Driver.hpp"


#define super IOService
OSDefineMetaClassAndStructors(HPQ6001Driver, IOService)

bool HPQ6001Driver::start(IOService* provider) {
    IOLog("HPQ6001Driver: Starting...\n");

    IOACPIPlatformDevice* acpiDevice = OSDynamicCast(IOACPIPlatformDevice, provider);
    if (!acpiDevice) {
        IOLog("HPQ6001Driver: Failed to cast provider to IOACPIPlatformDevice\n");
        return false;
    }

    _acpiDevice = acpiDevice;
    _acpiDevice->retain();

    OSObject* context = this;
    if (kIOReturnSuccess != _acpiDevice->registerForNotification(
        kIOACPIMessageDeviceNotification,
        notifyHandler,
        context
    )) {
        IOLog("HPQ6001Driver: Failed to register ACPI notification\n");
        return false;
    }

    IOLog("HPQ6001Driver: ACPI notification registered\n");
    return super::start(provider);
}

void HPQ6001Driver::stop(IOService* provider) {
    IOLog("HPQ6001Driver: Stopping...\n");
    if (_acpiDevice) {
        _acpiDevice->release();
        _acpiDevice = nullptr;
    }
    super::stop(provider);
}

IOReturn HPQ6001Driver::notifyHandler(OSObject* target, void* refCon, IOACPIPlatformDevice* device, UInt32 event) {
    if (event != 0x80) {
        IOLog("HPQ6001Driver: Unknown ACPI event 0x%x\n", event);
        return kIOReturnSuccess;
    }

    IOLog("HPQ6001Driver: ACPI event 0x80 (Airplane Mode button) triggered\n");


    return kIOReturnSuccess;
}
