#ifndef ALARM_H
#define ALARM_H

#include <iostream>
#include <string>
#include "SmartDevice.h"
#include "AlarmState.h"
#include "Deactivated.h"

/**
 * @file Alarm.h
 * @brief Defines the Alarm class for managing smart home alarm systems.
 * 
 * Alarm represents a security alarm in the smart home automation system. It allows
 * controlling the alarm's state, loudness, and security level through interaction with the AlarmState interface.
 * 
 * @warning Ensure proper cleanup of the AlarmState pointer to avoid memory issues.
 * 
 */
class Alarm : public SmartDevice {
private:
    std::string alarmType; 
    int loudness; 
    std::string security; 
    AlarmState* state; /**< Pointer to the current state of the alarm */

public:
    /**
     * @brief Constructs an Alarm object with a specified type, loudness, and security level.
     * 
     * @param typeAlarm The type or model of the alarm.
     * @param decibels The loudness level in decibels.
     * @param grade The security level or category of the alarm.
     */
    Alarm(std::string typeAlarm, int decibels, const std::string& grade);

    /**
     * @brief Destructor for the Alarm class.
     * 
     * Responsible for cleaning up the AlarmState pointer.
     */
    ~Alarm();

    /**
     * @brief Performs an action based on the current alarm state.
     * 
     * Executes the current state's action on the alarm.
     */
    void performAction() override;

    /**
     * @brief Returns type of smart device.
     * 
     * @return A string representing the device type.
     */
    std::string getDeviceType() override;

    /**
     * @brief Gets the current status of the alarm.
     * 
     * Returns a string representation of the alarm's current state, loudness, and security level.
     * 
     * @return A string describing the current status of the alarm.
     */
    std::string getStatus() const;

    /**
     * @brief Sets the state of the alarm (e.g., activated/deactivated).
     * 
     * Allows changing the alarm's state by providing a new AlarmState object.
     * 
     * @param status Pointer to a new AlarmState object.
     */
    void setStatus(AlarmState* status);

    /**
     * @brief Observer update method.
     * 
     * This method to notify the alarm of changes, allowing it to update its state.
     */
    void update() override;
};

#endif
