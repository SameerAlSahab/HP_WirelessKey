#ifndef HPQ6001Driver_hpp
#define HPQ6001Driver_hpp

#include <IOKit/IOService.h>
#include <IOKit/acpi/IOACPIPlatformDevice.h>

class HPQ6001Driver : public IOService {
    OSDeclareDefaultStructors(HPQ6001Driver)

public:
    virtual bool start(IOService* provider) override;
    virtual void stop(IOService* provider) override;

    static IOReturn notifyHandler(OSObject* target, void* refCon,
                                  IOACPIPlatformDevice* device, UInt32 event);
};

#endif /* HPQ6001Driver_hpp */
