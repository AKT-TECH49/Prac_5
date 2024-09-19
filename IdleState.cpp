#include "IdleState.h"
#include "MonitorState.h"

void IdleState::read(Thermostat *thermo)
{
    thermo->setState(new MonitorState());
     MonitorState* state = new MonitorState();
     state->read(thermo);
     delete state;
    std::cout<<"ThermoStat is now monitoring temperature. \n";
}

std::string IdleState::toString() const
{
    return "Idle";
}

bool IdleState::isCold() const
{
    return false;
}

bool IdleState::isHot() const
{
    return false;
}

bool IdleState::isMild() const
{
    return false;
}
