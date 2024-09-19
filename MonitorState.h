#ifndef MONITORSTATE_H
#define MONITORSTATE_H

#include <iostream>
#include <string>
#include "ThermoState.h"
#include "Thermostat.h"

class MonitorState: public ThermostatState
{
    public:
    void read(Thermostat* thermostat) override;
    std::string toString() const override;
    bool isCold() const override;
    bool isHot() const override;
    bool isMild() const override;

};


#endif