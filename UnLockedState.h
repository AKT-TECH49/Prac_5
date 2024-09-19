#ifndef UNLOCKEDSTATE_H
#define UNLOCKEDSTATE_H

#include <iostream>
#include <string>
#include "DoorLState.h"

class UnlockedState : public DoorLockState
{
    public:
    void pressButton(DoorLock* lock) override;
    std::string toString() override;
};





#endif