#include "SmartDeviceCommand.h"
#include "LockAllDoors.h"
#include "LockedState.h"
#include "DoorLock.h"

LockAllDoors::LockAllDoors(DoorLock *doorLock)
    : doorLock(doorLock) {}

LockAllDoors::~LockAllDoors()
{
    // if (doorLock != NULL )
    // {
    //     delete doorLock;
        doorLock = NULL;
    // }
}

void LockAllDoors::execute()
{
    // Check if the door is already locked
    if (doorLock->getStat() == "Unlocked")
    {
        doorLock->performAction(); // This will lock the door if it's unlocked
        std::cout << doorLock->getDeviceType() << " is now locked." << std::endl;
    }
    else
    {
        std::cout << doorLock->getDeviceType() << " is already locked." << std::endl;
    }
}