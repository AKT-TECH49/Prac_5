#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"
#include "ThermoState.h"
#include "IdleState.h"

#include <iostream>
#include <string>

/**
 * @file Thermostat.h
 * @brief Thermostat class for managing smart home thermostats.
 * 
 * The Thermostat represents a temp control device in the smart home automation system.
 * It allows monitoring and controlling the temp and managing thermostat states like idle, heating, or cooling.
 * 
 * @warning Ensure that the ThermostatState pointer is managed to avoid memory leaks.
 * 
 *  @author Mpho_Siminya_u21824241 and Amantle_Temo_u23539764
 *  @version 1.0
 * 
 */
class Thermostat : public SmartDevice {
private:
    int temperature; 
    std::string name;
    ThermostatState* state; 

public:
    /**
     * @brief Constructs Thermostat object with a specified type.
     * 
     * @param thermoType The type of the thermostat.
     */
    Thermostat(const std::string& thermoType);

    /**
     * @brief Destructor for the Thermostat class.
     * 
     * Responsible for cleaning up the ThermostatState pointer.
     */
    ~Thermostat();

    /**
     * @brief Default constructor for Thermostat class.
     */
    Thermostat();

    /**
     * @brief Gets the current status of the thermostat.
     * 
     * Returns a string representation of the thermostat's current state and temperature.
     * 
     * @return A string describing the current status of the thermostat.
     */
    std::string getStatus() const;

    /**
     * @brief Sets the state of the thermostat.
     * 
     * This method allows changing the thermostat's state by providing a new ThermostatState object.
     * 
     * @param state Pointer to a new ThermostatState object.
     */
    void setState(ThermostatState* state);

    /**
     * @brief Performs an action based on the current thermostat state.
     * 
     * Executes the current state's action on the thermostat (e.g., heating or cooling).
     */
    void performAction() override;

    /**
     * @brief Returns type of smart device.
     * 
     * @return A string representing device type.
     */
    std::string getDeviceType() override;

    /**
     * @brief Sets the target temp of the thermostat.
     * 
     * @param targetTemperature The desired temp to set.
     */
    void setTemperature(int targetTemperature);

    /**
     * @brief Gets the current temp of the thermostat.
     * 
     * @return The current temp setting.
     */
    int getTemperature() const;

    /**
     * @brief Observer update method.
     * 
     * This method allows thermostat to update its state when notified of changes.
     */
    void update() override;
};

#endif
