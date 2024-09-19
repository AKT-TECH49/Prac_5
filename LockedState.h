#ifndef LOCKEDSTATE_H
#define LOCKEDSTATE_H

#include <iostream>
#include <string>
#include "DoorLState.h"

class LockedState : public DoorLockState
{
    public:
    void pressButton(DoorLock* locky) override;
    std::string toString() override;
};


#endif

