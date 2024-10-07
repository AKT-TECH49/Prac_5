#include "SmartDeviceCommand.h"
#include "TurnOffAllLights.h"
#include "OffState.h"
#include "Light.h"

TurnOffAllLights::TurnOffAllLights(Light *light)
    : light(light) {}


TurnOffAllLights::~TurnOffAllLights()
 {
//     if(light)
//     {
//         delete light;
         light = NULL;
//     }
 }


void TurnOffAllLights::execute()
{
    // Set the light state to OffState
    std::string currState = light->getStatus();

    if (currState == "Off")
    {
       std::cout<<light->getDeviceType()<<" is already off. "<<std::endl;
    }
    else
    {
         OffState* newS = new OffState();
        light->setState(newS); // Change light to OffState
        std::cout << light->getDeviceType() << " is now turned off.\n";
    }

}