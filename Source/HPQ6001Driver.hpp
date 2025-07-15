#ifndef _HPQ6001_DRIVER_H
#define _HPQ6001_DRIVER_H

#include <IOKit/IOService.h>
#include <IOKit/acpi/IOACPIPlatformDevice.h>

class HPQ6001Driver : public IOService {
    OSDeclareDefaultStructors(HPQ6001Driver)

public:
    virtual bool start(IOService* provider) override;
    virtual void stop(IOService* provider) override;

private:
    static IOReturn notifyHandler(OSObject* target, void* refCon, IOACPIPlatformDevice* device, UInt32 event);

    IOACPIPlatformDevice* _acpiDevice;
};

#endif
