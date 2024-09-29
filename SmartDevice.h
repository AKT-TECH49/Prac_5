#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <iostream>
#include <string>
#include "LightState.h"
#include "DoorLState.h"
#include "ThermoState.h"

/**
 * @file SmartDevice.h
 * @brief Defines the abstract base class SmartDevice for all smart devices in the home automation system.
 * 
 * SmartDevice acts as a base class for various smart home devices.
 */
class SmartDevice
{
private:
    //std::string name;
    int id;

public:
    /**
     * @brief Virtual destructor for the SmartDevice class.
     * 
     * Ensures proper cleanup of derived classes when a SmartDevice object is destroyed.
     */
    virtual ~SmartDevice() = default;

    /**
     * @brief Constructs a SmartDevice with a specified name and type ID.
     * 
     * @param name The name of the device.
     * @param typeId The unique type identifier for the device.
     */
    SmartDevice(int typeId);

    /**
     * @brief Pure virtual function to get the device type.
     * 
     * Derived classes must implement this method to return the type of the device (e.g., light, door lock, thermostat).
     * 
     * @return A string representing the device type.
     */
    virtual std::string getDeviceType() = 0;

    /**
     * @brief Pure virtual function to perform the device's main action.
     * 
     * This method must be implemented by derived classes to perform the specific action of the device.
     */
    virtual void performAction() = 0;

    /**
     * @brief Gets the name of the smart device.
     * 
     * @return The name of the smart device as a string.
     */
    //std::string getName() const;

    /**
     * @brief Gets the unique ID of the smart device.
     * 
     * @return The device's unique ID as an integer.
     */
    int getId();

    /**
     * @brief Pure virtual function to update the state of the device.
     * 
     * This method must be implemented by derived classes to define how the device reacts to state changes.
     */
    virtual void update() = 0;
};

#endif // SMARTDEVICE_H
