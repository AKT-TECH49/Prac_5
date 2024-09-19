#include "MildTemp.h"
#include "Thermostat.h"

void MildState::read(Thermostat *thermostat)
{
    std::cout<<"~# MILD, Maintaining mild settings.\n";
    std::cout<<"State is: "<<thermostat->getStatus()<<std::endl;
}

std::string MildState::toString() const
{
    return "Mild";
}

bool MildState::isMild() const
{
    return true;
}

bool MildState::isCold() const
{
    return false;
}

bool MildState::isHot() const
{
    return false;
}
