#include "Thermostat.h"

Thermostat::Thermostat(const std::string &thermoType, int readTemp):SmartDevice(thermoType ,33 )
{
    this->name = thermoType;
    this->temperature = readTemp;
    state = new IdleState();
}

std::string Thermostat::getStatus() const
{
    std::string state_name = state->toString();
    return  state_name;
}

Thermostat::~Thermostat()
{
    delete state;
}

void Thermostat::setState(ThermostatState *state)
{
    delete this->state;
    this->state = state;
}

void Thermostat::performAction()
{
    state->read(this);
}

std::string Thermostat::getDeviceType()
{
    return name;
}

void Thermostat::setTemperature(int tempy)
{
    this->temperature = tempy;
}

int Thermostat::getTemperature() const
{
    return this->temperature;
}
