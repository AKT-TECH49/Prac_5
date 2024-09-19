#include "Light.h"
#include "OffState.h"


Light::Light(const std::string &lightType, int initBrightness, int wattz):SmartDevice(lightType , 11)
{
    this->brightness = initBrightness;
    this->power = wattz;
    this->name = lightType;
    state = new OffState();
}

Light::~Light()
{
    delete this->state;
}

std::string Light::getStatus() const
{
    std::string state_name = state->toString();
    return  state_name;
}

void Light::setState(LightState *light)
{
    delete this->state;
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
