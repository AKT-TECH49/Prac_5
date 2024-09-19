#ifndef MILDSTATE_H
#define MILDSTATE_H

#include <iostream>
#include <string>
#include "ThermoState.h"

class MildState : public ThermostatState
{
    public:
    void read(Thermostat* thermostat) override;
    std::string toString() const override;
    bool isMild() const override;
   bool isCold() const override;
    bool isHot() const override;

};


#endif