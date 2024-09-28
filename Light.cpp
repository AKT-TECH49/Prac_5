#include "Light.h"
#include "OffState.h"


Light::Light(const std::string &lightType, int initBrightness, int wattz):SmartDevice( 11)
{
    this->brightness = initBrightness;
    this->power = wattz;
    this->name = lightType;
    state = new OffState();
} 

Light::~Light()
{
    if(state)
    {
    delete this->state;
    state = NULL;
    }

}

std::string Light::getStatus() const
{
    std::string state_name = state->toString();
    return  state_name;
}

void Light::setState(LightState *light)
{
   if(this->state)
   {
    delete this->state;
    state = NULL;
   }
    this->state = light;
}

void Light::performAction()
{
    state->toggle(this);
}

std::string Light::getDeviceType()
{
    return this->name;
}

void Light::update()
{
     if(state->toString() == "Off")
     {
        state->toggle(this);
     }
     else
     {
        std::cout<<"!Light is turned on already!"<<std::endl;
     }
}
