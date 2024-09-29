#ifndef CONTROL_H
#define CONTROL_H

#include "SmartDevice.h"
#include "Sensor.h"
#include <vector>
#include <iostream>

/**
 * @file Control.h
 * @brief Defines the class that manages sensors and devices in a smart home system.
 * 
 * The Control class provides functionality to add sensors, add devices, and notify specific devices.
 */
class Control
{
private:
    std::vector<Sensor*> sensors;
    std::vector<SmartDevice*> devices; 

public:
    /**
     * @brief Destructor for the Control class.
     * 
     * Cleans up the sensors and devices managed by the control system.
     */
    ~Control();

    /**
     * @brief Adds a sensor to the control system.
     * 
     * @param sensor Pointer to the Sensor to be added.
     */
    void addSensor(Sensor* sensor);

    /**
     * @brief Adds a smart device to the control system.
     * 
     * @param device Pointer to the SmartDevice to be added.
     */
    void addDevice(SmartDevice* device);

    /**
     * @brief Removes a sensor to the control system.
     * 
     * @param sensor Pointer to the Sensor to be added.
     */
    void removeSensor(Sensor* sensor);

    /**
     * @brief Remove a smart device to the control system.
     * 
     * @param device Pointer to the SmartDevice to be added.
     */
    void removeDevice(SmartDevice* device);

    /**
     * @brief Notifies a specific smart device about an event.
     * 
     * This method triggers a notification or action for the provided device.
     * 
     * @param device Pointer to the SmartDevice that needs to be notified.
     */
    void notifySpecificDevice(SmartDevice* device);
};

#endif // CONTROL_H
