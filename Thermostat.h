#ifndef THERMOSTAT_H
#define THERMOSTAT_H


#include "SmartDevice.h"
#include "ThermoState.h"
#include "IdleState.h"

#include <iostream>
#include <string>


class Thermostat : public SmartDevice
{
private:
    int temperature; 
    std::string name;
    ThermostatState* state;

    public:
    Thermostat(const std::string& thermoType ,  int readTemp ) ;
    ~Thermostat();
    //
    std::string getStatus() const;
    void setState(ThermostatState* state) ;
    //
    void performAction();
    //
    std::string getDeviceType() override;
    //
    void setTemperature(int targetTemperature);
    int getTemperature() const;

};
#endif 