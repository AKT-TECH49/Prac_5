#include "MildTemp.h"
#include "Thermostat.h"

// read the temperature on the thermostat
void MildState::read(Thermostat *thermostat)
{
    std::cout<<"~# MILD, Maintaining mild settings.\n";
    std::cout<<"State is: "<<thermostat->getStatus()<<std::endl;
}

// label of the temperature 
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
