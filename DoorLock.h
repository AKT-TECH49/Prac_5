#ifndef DOORLOCK_H
#define DOORLOCK_H


#include "SmartDevice.h"
#include "DoorLState.h"
#include "UnLockedState.h"
#include <iostream>
#include <string>
#include <vector>

class DoorLock : public SmartDevice 
{
    private: 
    int lockStrength;        
    std::string securityLevel;  
    std::string name;
    DoorLockState* state ;


    public:
    DoorLock(std::string lockType , int grade ,  const std::string& secLevel);
    //
    std::string getStat() const ;
    void setStat(DoorLockState* state) ;
    //
    void performAction();
    //
    std::string getDeviceType() override;
    //


};


#endif 