#include "HotTemp.h"
#include "Thermostat.h"

void HotState::read(Thermostat *thermostat)
{
    std::cout<<"~#HOT, Maintaing high temperature settings.\n";
    std::cout<<"State is: "<<thermostat->getStatus() <<std::endl;
}

std::string HotState::toString() const
{
    return "Hot";
}

bool HotState::isHot() const
{
    return true;
}

bool HotState::isCold() const
{
    return false;
}

bool HotState::isMild() const
{
    return false;
}