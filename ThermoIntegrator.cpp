#include "ThermoIntegrator.h"
#include "IdleState.h"
#include "MonitorState.h"


 SmartThermostatIntegrator:: SmartThermostatIntegrator(LegendThermo *thermo, const std::string &name):SmartDevice(100)
{
    this->thermo = thermo;
    this->name = name;

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
    int inctemp = getTemP();
    if(inctemp > 25 )
    {
      inctemp -= 5;   
    }
    else
    {
        inctemp += 4;
    }
    setTemp(inctemp);

    std::cout<<"Current Temp(°C) is: "<<getTemP()<<std::endl;

    // MonitorState* state = new MonitorState();
    // state->read(this);
    // delete state;

}

std::string  SmartThermostatIntegrator::getDeviceType()
{
    return "Thermostat Adpater";
}

void SmartThermostatIntegrator::update()
{
    // do nothing
}
