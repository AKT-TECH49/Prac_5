#include "LockedState.h"
#include "DoorLock.h"
#include "UnLockedState.h"

void LockedState::pressButton(DoorLock *locky)
{
    locky->setStat(new UnlockedState());
    std::cout<<"~@ Door is now unlocked. \n";

}

std::string LockedState::toString()
{
    return "Locked";
}