#include "DoorLock.h"
#include "LockedState.h"

DoorLock::DoorLock(std::string lockType, int grade, const std::string &secLevel):SmartDevice(22)
{
    this->name = lockType;
    this->lockStrength = grade;
    this->securityLevel =secLevel;
    this->state = new UnlockedState();

}

DoorLock::~DoorLock()
{
     if(state)
    {
    delete this->state;
    state = NULL;
    }
}

std::string DoorLock::getStat() const
{
   if(state)
   {
        std::string state_name = state->toString();
    return  state_name;
   }
   else
    {
        return "ERROR";
    }
}

void DoorLock::setStat(DoorLockState *state)
{
    this->state = state;
}

void DoorLock::performAction()
{
    
    if(state->toString() == "Unlocked")
    {
        state->pressButton(this);
        std::cout<<"LOCKED THE DOOR \n";
    }
    else 
    {

        std::cout<<"Door is LOCKED already\n";
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
