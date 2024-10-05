#include "SmartDeviceCommand.h"
#include "SwitchThermo.h"
#include "Thermostat.h"

SwitchThermo::SwitchThermo(Thermostat *thermo, int temp)
    : thermostat(thermo), newTemperature(temp) {}

SwitchThermo::~SwitchThermo()
{
    if (thermostat)
    {
        delete thermostat;
        thermostat = NULL;
    }
}

void SwitchThermo::execute()
{
    thermostat->setTemperature(newTemperature);
    thermostat->performAction(); 
}