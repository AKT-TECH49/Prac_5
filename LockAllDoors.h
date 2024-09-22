#ifndef LOCKALLDOORS_H
#define LOCKALLDOORS_H

#include "SmartDeviceCommand.h"
#include "LockedState.h"
#include "DoorLock.h"

// Concrete Command to lock all the doors in a room
class LockAllDoors : public SmartDeviceCommand
{
private:
    DoorLock *doorLock;

public:
    LockAllDoors(DoorLock *doorLock);
    virtual~LockAllDoors();
    void execute() override;
};

#endif // LOCKALLDOORS_H
