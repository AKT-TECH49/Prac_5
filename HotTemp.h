#ifndef HOTSTATE_H
#define HOTSTATE_H

#include <iostream>
#include <string>
#include "ThermoState.h"

class HotState : public ThermostatState
{
    public:
    void read(Thermostat* thermostat) override;
    std::string toString() const override;
    bool isHot() const override;
    bool isCold() const override;
    bool isMild() const override;

};


#endif