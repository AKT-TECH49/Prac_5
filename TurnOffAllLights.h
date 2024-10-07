#ifndef TURNOFFALLLIGHTS_H
#define TURNOFFALLLIGHTS_H

#include "SmartDeviceCommand.h"
#include "OffState.h"
#include "Light.h"

/**
 * @file TurnOffAllLights.h
 * @brief Concrete command to turn off all the lights in a room.
 * 
 * This class implements the Command interface and provides the execute method to turn off all lights.
 * 
 * 
 *  @author Mpho_Siminya_u21824241 and Amantle_Temo_u23539764
 *  @version 1.0
 */
class TurnOffAllLights : public SmartDeviceCommand {
private:
    Light* light; /**< Pointer to the Light object being controlled. */

public:
    /**
     * @brief Constructs a TurnOffAllLights command with a specific Light.
     * 
     * @param light Pointer to the Light object to be turned off.
     */
    TurnOffAllLights(Light* light);

    /**
     * @brief Destructor for the TurnOffAllLights command.
     */
    ~TurnOffAllLights();

    /**
     * @brief Executes the command to turn off all lights.
     */
    void execute() override;
};

#endif // TURNOFFALLLIGHTS_H
