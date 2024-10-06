#include "ThermoIntegrator.h"
#include "IdleState.h"
#include "MonitorState.h"


 SmartThermostatIntegrator:: SmartThermostatIntegrator(LegendThermo *thermo, const std::string &name):SmartDevice(100)
{
    this->thermo = thermo;
    this->name = name;

}

SmartThermostatIntegrator::~SmartThermostatIntegrator()
{
    if(thermo)
    {
        delete thermo;
        thermo = NULL;
    }
}

void  SmartThermostatIntegrator::setTemp(int t ) 
{
    thermo->adjustTemperature(t);
}

int  SmartThermostatIntegrator::getTemP() const
{
    return thermo->readTemperature();
}



void  SmartThermostatIntegrator::performAction() 
{
    std::cout<< " Action being performed on ThermoStat Adapter: "<<std::endl;
    int readTemp = getTemP();

    if(readTemp >= 25 )
    {
      readTemp -= 5 ;
      setTemp(readTemp);
      std::cout<<"Reducing the temperature...\n";
    }
    else if( readTemp < 18)
    {
        readTemp += 3 ;
        setTemp(readTemp);
        std::cout<<"Increasing the temperature...\n";
    }
    else
    {
        std::cout<<"Optimal Temperature...\n";
    }
    std::cout<<"Adjusted Temp(°C) is: "<<getTemP()<<std::endl;

}

std::string  SmartThermostatIntegrator::getDeviceType()
{
    return "Thermostat Adpater";
}

void SmartThermostatIntegrator::update()
{
   std::cout<<"~Integration~ \n";
}