#include "HPQ6001Driver.hpp"
#include <IOKit/IOLib.h>

#define super IOService
OSDefineMetaClassAndStructors(HPQ6001Driver, IOService)

bool HPQ6001Driver::start(IOService* provider) {
    IOLog("HPQ6001Driver: Start method called.\n");

    _acpiDevice = OSDynamicCast(IOACPIPlatformDevice, provider);
    if (_acpiDevice) {
        IOLog("HPQ6001Driver: HPQ6001 ACPI device detected.\n");
    } else {
        IOLog("HPQ6001Driver: Not an ACPI device or HPQ6001 not found.\n");
    }

    return super::start(provider);
}

void HPQ6001Driver::stop(IOService* provider) {
    IOLog("HPQ6001Driver: Stop method called.\n");
    super::stop(provider);
}
