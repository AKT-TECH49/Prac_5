#include "SmartDeviceCommand.h"
#include "SwitchThermo.h"
#include "Thermostat.h"

SwitchThermo::SwitchThermo(Thermostat *thermo, int temp)
    : thermostat(thermo), newTemperature(temp) {}

SwitchThermo::~SwitchThermo() {
    // Optional: Destructor implementation
}

void SwitchThermo::execute()
{
    thermostat->setTemperature(newTemperature);
    thermostat->performAction(); // This will trigger the thermostat state change
}