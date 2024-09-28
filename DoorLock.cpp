#include "DoorLock.h"
#include "LockedState.h"

DoorLock::DoorLock(std::string lockType, int grade, const std::string &secLevel):SmartDevice(name ,22)
{
    this->name = lockType;
    this->lockStrength = grade;
    this->securityLevel =secLevel;
    state = new UnlockedState();
}

DoorLock::~DoorLock()
{
    delete state;
}

std::string DoorLock::getStat() const
{
     std::string state_name = state->toString();
    return  state_name;
}

void DoorLock::setStat(DoorLockState *state)
{
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

void DoorLock::update()
{
    if(state->toString() == "Unlocked")
    {
        state->pressButton(this);
        std::cout<<"DoorLock is now LOCKED"<<std::endl;
    }
    else
    {
        std::cout<<"DOORLOCK IS ALREADY LOCKED \t - ~_~ 'HEWW'  "<< std::endl;
    }
}
