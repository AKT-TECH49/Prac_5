#ifndef SWITCHTHERMO_H
#define SWITCHTHERMO_H

#include "SmartDeviceCommand.h"
#include "Thermostat.h"

/**
 * @file SwitchThermo.h
 * @brief Concrete command to switch the thermostat to a new temperature.
 * 
 * This class implements the Command interface and provides the execute method to switch the thermostat's temperature.
 */
class SwitchThermo : public SmartDeviceCommand {
private:
    Thermostat* thermostat; /**< Pointer to the Thermostat object being controlled. */
    int newTemperature; /**< New temperature to set the thermostat to. */

public:
    /**
     * @brief Constructs a SwitchThermo command with a specific thermostat and temperature.
     * 
     * @param thermo Pointer to the Thermostat object.
     * @param temp The new temperature to set.
     */
    SwitchThermo(Thermostat* thermo, int temp);

    /**
     * @brief Destructor for the SwitchThermo command.
     */
    virtual ~SwitchThermo();

    /**
     * @brief Executes the command to set the thermostat to the new temperature.
     */
    void execute() override;
};

#endif // SWITCHTHERMO_H
