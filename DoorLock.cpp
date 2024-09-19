#include "DoorLock.h"
#include "LockedState.h"

DoorLock::DoorLock(std::string lockType, int grade, const std::string &secLevel):SmartDevice(name ,22)
{
    this->name = lockType;
    this->lockStrength = grade;
    this->securityLevel =secLevel;
    state = new UnlockedState();
}

std::string DoorLock::getStat() const
{
     std::string state_name = state->toString();
    return  state_name;
}

void DoorLock::setStat(DoorLockState *state)
{
    delete state;
    this->state = state;
}

void DoorLock::performAction()
{
    
    if(state->toString() == "Unlocked")
    {
        state = new LockedState();
        std::cout<<"LOCKED THE DOOR \n";
    }
    else 
    {

        state = new UnlockedState();
        std::cout<<"UNLOCKED THE DOOR \n";
    }
}

std::string DoorLock::getDeviceType()
{
    return name;
}
