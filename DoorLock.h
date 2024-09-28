#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "SmartDevice.h"
#include "DoorLState.h"
#include "UnLockedState.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @file DoorLock.h
 * @brief Defines the DoorLock class for managing smart home door locks.
 * 
 * The DoorLock class represents a door lock in the smart home automation system. It allows
 * controlling the lock's state, security level, and lock strength.
 * 
 * @warning Ensure the state object is correctly handled to avoid memory leaks.
 * 
 * @todo Implement auto-lock functionality after a set period of inactivity.
 */
class DoorLock : public SmartDevice {
private:
    int lockStrength;        /**< Represents the strength of the lock (grade scale). */
    std::string securityLevel;  /**< Security level assigned to the lock (e.g., "High", "Low"). */
    std::string name;          /**< Name of the door lock (e.g., "Front Door"). */
    DoorLockState* state;      /**< Pointer to the current state of the lock (locked/unlocked). */

    public:
    DoorLock(std::string lockType , int grade ,  const std::string& secLevel);
     ~DoorLock();
    //
    std::string getStat() const ;
    void setStat(DoorLockState* state) ;
    //
    // void performAction();
     void performAction() override;
    //
    std::string getDeviceType() override;

    /**
     * @brief Observer update method.
     * 
     * This method allows the door lock to update its state when notified of changes.
     */
    void update() override;
};


#endif 