#ifndef THERMOSTATSTATE_H
#define THERMOSTATSTATE_H

#include <iostream>
#include <string>

class Thermostat;

class ThermostatState 
{
    public:
    virtual ~ThermostatState() = default;

    virtual void read(Thermostat* thermo) = 0;
    virtual std::string toString() const = 0;
    //
     virtual bool isCold() const;
    virtual bool isHot() const;
    virtual bool isMild() const;
   

};
#endif