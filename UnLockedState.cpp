#include "UnLockedState.h"
#include "LockedState.h"
#include "DoorLock.h"
#include <string>


void UnlockedState::pressButton(DoorLock *lock)
{
    LockedState* newS = new LockedState();
    lock->setStat(newS);
    std::cout<<"~@Door is now LOCKED!! \n";
}

std::string UnlockedState::toString() 
{
    return "Unlocked";
}

