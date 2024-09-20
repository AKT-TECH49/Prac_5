#ifndef SENSOR_H
#define SENSOR_H

#include "SmartDevice.h"
#include <vector>

class Sensor {
public:
    virtual ~Sensor() = default;
    virtual void addDevice(SmartDevice* observer) = 0;
    virtual void removeDevice(SmartDevice* observer) = 0;
    virtual void notifyDevices() = 0;
};

#endif 
