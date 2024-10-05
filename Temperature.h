#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"
#include <vector>
#include <iostream>

class Temperature : public Sensor {
private:
    std::vector<SmartDevice*> devices;  
    std::string name;

public:
    Temperature(const std::string& name);
    ~Temperature();
    void addDevice(SmartDevice* device) override;
    void removeDevice(SmartDevice* device) override;
    void notifyDevices() override;
   void detectTemp();

};

#endif 
