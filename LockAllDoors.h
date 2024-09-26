#ifndef LOCKALLDOORS_H
#define LOCKALLDOORS_H

#include "SmartDeviceCommand.h"
#include "LockedState.h"
#include "DoorLock.h"

/**
 * @file LockAllDoors.h
 * @brief Concrete command to lock all doors in a smart home automation system.
 * 
 * This class implements the Command interface and provides the execute method to lock all doors.
 */
class LockAllDoors : public SmartDeviceCommand {
private:
    DoorLock* doorLock; 

public:
    /**
     * @brief Constructs a LockAllDoors command with a specific DoorLock.
     * 
     * @param doorLock Pointer to the DoorLock object to be locked.
     */
    LockAllDoors(DoorLock* doorLock);

    /**
     * @brief Destructor for the LockAllDoors command.
     */
    virtual ~LockAllDoors();

    /**
     * @brief Executes the command to lock all doors.
     */
    void execute() override;
};

#endif // LOCKALLDOORS_H
