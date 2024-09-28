#ifndef  SmartThermostatIntegrator_H
#define  SmartThermostatIntegrator_H

#include "SmartDevice.h"
#include "LegendThermo.h"

class  SmartThermostatIntegrator : public SmartDevice
{
    private:
    LegendThermo* thermo;
    std::string name;

    public:
    SmartThermostatIntegrator(LegendThermo* thermo , const std::string& name);
    void setTemp(int t);
    int getTemP() const;
    //
    void performAction() override;
    std::string getDeviceType() override;

    //
    void update() override;
};
#endif