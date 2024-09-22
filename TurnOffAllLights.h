#ifndef TURNOFFALLLIGHTS_H
#define TURNOFFALLLIGHTS_H

#include "SmartDeviceCommand.h"
#include "OffState.h"
#include "Light.h"

// Concrete Command to turn off all the lights in a room
class TurnOffAllLights : public SmartDeviceCommand
{
private:
    Light *light; // use the light object

public:
    TurnOffAllLights(Light *light);
    virtual~TurnOffAllLights();
    void execute() override;
};

#endif // TURNOFFALLLIGHTS_H
