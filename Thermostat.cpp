#include "Thermostat.h"
#include "MonitorState.h"

Thermostat::Thermostat(const std::string &thermoType):SmartDevice( 33 )
{
    this->name = thermoType;
    this->temperature =0;
    state = new IdleState();
}

std::string Thermostat::getStatus() const
{
    std::string state_name = state->toString();
    return  state_name;
}

Thermostat::~Thermostat()
{
     if(state)
    {
    delete this->state;
    state = NULL;
    }
}

void Thermostat::setState(ThermostatState *state)
{
    if(state)
    {
    delete this->state;
    }
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

void Thermostat::update()
{
    if(state->toString() == "Idle")
    {
        state->read(this);
    }
    else if(state->toString() == "Monitoring")
    {
        state->read(this);
    }
    else
    {
        MonitorState* newS = new MonitorState();
        setState(newS);
        newS->read(this);
        //delete newS;
    }

}
