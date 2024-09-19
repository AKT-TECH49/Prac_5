#ifndef COLDSTATE_H
#define COLDSTATE_H

#include <iostream>
#include <string>
#include "ThermoState.h"

class ColdState : public ThermostatState
{
    public:
    void read(Thermostat* thermostat) override;
    std::string toString() const override;
    bool isCold() const override ;
    bool isHot() const override;
    bool isMild() const override;

};


#endif