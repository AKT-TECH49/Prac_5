#ifndef CONTROL_H
#define CONTROL_H

#include "SmartDevice.h"
#include "Sensor.h"
#include <vector>
#include <iostream>

class Control
{
    private:
    std::vector<Sensor*> sensors;    
    std::vector<SmartDevice*> devices;  

    public:
    ~Control();
    void addSensor(Sensor* sensor);
    void addDevice(SmartDevice* device);
    void removeSensor(Sensor* sensor);
    void removeDevice(SmartDevice* device);
    void notifySpecificDevice(SmartDevice* device);

};

#endif 
