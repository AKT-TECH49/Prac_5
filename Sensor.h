#ifndef SENSOR_H
#define SENSOR_H

#include "SmartDevice.h"
#include <vector>

/**
 * @file Sensor.h
 * @brief Defines the Sensor class interface for managing observers in a smart home system.
 * 
 * The Sensor class serves as an interface for sensors that monitor changes in the environment 
 * and notify associated smart devices.
 */
class Sensor {
public:
    /**
     * @brief Virtual destructor for the Sensor class.
     * 
     * Ensures proper cleanup of derived classes when a Sensor object is destroyed.
     */
    virtual ~Sensor() = default;

    /**
     * @brief Adds a smart device as an observer to the sensor.
     * 
     * @param observer Pointer to the SmartDevice that will observe the sensor's changes.
     */
    virtual void addDevice(SmartDevice* observer) = 0;

    /**
     * @brief Removes a smart device from the sensor's observer list.
     * 
     * @param observer Pointer to the SmartDevice to be removed from the observer list.
     */
    virtual void removeDevice(SmartDevice* observer) = 0;

    /**
     * @brief Notifies all registered smart devices (observers) of a change detected by the sensor.
     * 
     * This method triggers a notification to all smart devices that have been added as observers.
     */
    virtual void notifyDevices() = 0;
};

#endif // SENSOR_H
