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
    /**
     * @brief Constructs a DoorLock object with a specified lock type, grade, and security level.
     * 
     * @param lockType The type or name of the lock (e.g., "Deadbolt").
     * @param grade The lock strength grade (1-5).
     * @param secLevel The security level assigned to the lock.
     */
    DoorLock(std::string lockType, int grade, const std::string& secLevel);

    /**
     * @brief Destructor for the DoorLock class.
     * 
     * Responsible for cleaning up the DoorLockState pointer.
     */
    ~DoorLock();

    /**
     * @brief Gets the current status of the door lock.
     * 
     * Returns a string representing the current state and security level of the lock.
     * 
     * @return A string describing the current status of the door lock.
     */
    std::string getStat() const;

    /**
     * @brief Sets the state of the door lock (locked/unlocked).
     * 
     * This method allows changing the lock's state by providing a new DoorLockState object.
     * 
     * @param state A pointer to the new DoorLockState object.
     */
    void setStat(DoorLockState* state);

    /**
     * @brief Performs an action based on the current lock state.
     * 
     * Executes the current state’s action on the lock (e.g., locking or unlocking).
     */
    void performAction() override;

    /**
     * @brief Returns the type of smart device (DoorLock).
     * 
     * @return A string representing the device type.
     */
    std::string getDeviceType() override;

    /**
     * @brief Observer update method.
     * 
     * This method allows the door lock to update its state when notified of changes.
     */
    void update() override;
};

#endif
