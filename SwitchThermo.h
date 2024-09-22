#ifndef SWITCHTHERMO_H
#define SWITCHTHERMO_H

#include "SmartDeviceCommand.h"
#include "Thermostat.h"

class SwitchThermo : public SmartDeviceCommand {
private:
    Thermostat* thermostat;
    int newTemperature; 

public:
    SwitchThermo(Thermostat* thermo, int temp);
    virtual~SwitchThermo();
    void execute() override;
};

#endif // SWITCHTHERMO_H
