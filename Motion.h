#ifndef MOTION_H
#define MOTION_H

#include "Sensor.h"
#include <vector>
#include <iostream>

class MotionSensor : public Sensor {
private:
    std::vector<SmartDevice*> devices; 
    std::string name; 

public:
    MotionSensor(const std::string& name);
    // ~MotionSensor();
    void addDevice(SmartDevice* device) override;
    void removeDevice(SmartDevice* device) override;
    void notifyDevices() override;
    void detectMotion();
};

#endif 
