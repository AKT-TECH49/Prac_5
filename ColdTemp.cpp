#include "ColdTemp.h"
#include "Thermostat.h"

// read value on the thermostat
void ColdState::read(Thermostat *thermostat)
{
    std::cout<<"~#COLD, Maintaining low temperature setting.\n";
    std::cout<<"State is: "<<thermostat->getStatus()<<std::endl;
}

// label the temperature 
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
