#ifndef HPQ6001Driver_hpp
#define HPQ6001Driver_hpp

#include <IOKit/IOService.h>
#include <IOKit/acpi/IOACPIPlatformDevice.h>

class HPQ6001Driver : public IOService {
    OSDeclareDefaultStructors(HPQ6001Driver)

private:
    IOACPIPlatformDevice* _acpiDevice;

public:
    virtual bool start(IOService* provider) override;
    virtual void stop(IOService* provider) override;
};

#endif /* HPQ6001Driver_hpp */
