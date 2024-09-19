#include "MonitorState.h"
#include "HotTemp.h"
#include "ColdTemp.h"
#include "MildTemp.h"

void MonitorState::read(Thermostat *thermostat)
{
    int readTemp = thermostat->getTemperature();
    if (readTemp < 18)
    {
        thermostat->setState(new ColdState());
        std::cout << "It's cold. Thermostat is set to Cold mode.\n";
    }
    else if (readTemp >= 18 && readTemp <= 25)
    {
        thermostat->setState(new MildState());
        std::cout << "Temperature is mild. Thermostat is set to Mild mode.\n";
    }
    else
    {
        thermostat->setState(new HotState());
        std::cout << "It's hot. Thermostat is set to Hot mode.\n";
    }
}

std::string MonitorState::toString() const
{
    return "Monitoring";
}

bool MonitorState::isCold() const
{
    return false;
}

bool MonitorState::isHot() const
{
    return false;
}

bool MonitorState::isMild() const
{
    return false;
}
