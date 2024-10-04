#include "SmartDeviceCommand.h"
#include "TurnOffAllLights.h"
#include "OffState.h"
#include "Light.h"

TurnOffAllLights::TurnOffAllLights(Light *light) 
    : light(light) {}

TurnOffAllLights::~TurnOffAllLights() {
    // Optional: Destructor implementation
}

void TurnOffAllLights::execute()
{
    // Set the light state to OffState
    if (light->getStatus() != "Off")
    {
        light->setState(new OffState()); // Change light to OffState
        std::cout << light->getDeviceType() << " is now turned off.\n";
    }
    else
    {
        std::cout << light->getDeviceType() << " is already off.\n";
    }
}