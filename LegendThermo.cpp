#include "LegendThermo.h"

LegendThermo::LegendThermo()
{
    this->currentTemp = 19;
}

void LegendThermo::adjustTemperature(int temp)
{
    this->currentTemp = temp;
    std::cout << "Temperature updated to : " << currentTemp << "°C" << std::endl;
}

int LegendThermo::readTemperature()
{
    return currentTemp;
}
