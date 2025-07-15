#include "HPQ6001Driver.hpp"

#define super IOService
OSDefineMetaClassAndStructors(HPQ6001Driver, IOService)

bool HPQ6001Driver::start(IOService* provider) {
    if (!super::start(provider)) {
        return false;
    }

    _acpiDevice = OSDynamicCast(IOACPIPlatformDevice, provider);
    if (_acpiDevice) {
        IOLog("HPQ6001Driver: Detected HPQ6001 ACPI device.\n");
    }

    return true;
}

void HPQ6001Driver::stop(IOService* provider) {
    IOLog("HPQ6001Driver: Stopping driver.\n");
    super::stop(provider);
}
