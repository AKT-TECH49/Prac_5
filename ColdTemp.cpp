#include "ColdTemp.h"
#include "Thermostat.h"

void ColdState::read(Thermostat *thermostat)
{
    std::cout<<"~#COLD, Maintaining low temperature setting.\n";
    std::cout<<"State is: "<<thermostat->getStatus()<<std::endl;
}

std::string ColdState::toString() const
{
    return "Cold";
}

bool ColdState::isCold() const
{
    return true;
}

bool ColdState::isHot() const
{
    return false;
}

bool ColdState::isMild() const
{
    return false;
}
