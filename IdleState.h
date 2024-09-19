#ifndef IDLESTATE_H
#define IDLESTATE_H

#include <iostream>
#include <string>
#include "ThermoState.h"


class IdleState : public ThermostatState
{
    public:
    void read(Thermostat* thermo) override;
    std::string toString() const override ;


     bool isCold() const override;
    bool isHot() const override;
    bool isMild() const override;
};


#endif