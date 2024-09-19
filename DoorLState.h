#ifndef DOORLOCKSTATE_H
#define DOORLOCKSTATE_H

#include <iostream>
#include <string>

class DoorLock;

class DoorLockState 
{
    public:
     virtual ~DoorLockState() = default;
    virtual void pressButton(DoorLock* doorlock) = 0;
    virtual std::string toString() = 0;

};
#endif