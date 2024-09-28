#include "LockedState.h"
#include "DoorLock.h"
#include "UnLockedState.h"

void LockedState::pressButton(DoorLock *locky)
{
    UnlockedState* newS = new UnlockedState();
    locky->setStat(newS);
    std::cout<<"~@ Door is now unlocked. \n";

}

std::string LockedState::toString()
{
    return "Locked";
}