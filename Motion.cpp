#include "Motion.h"

MotionSensor::MotionSensor(const std::string &name)
{
    this->name = name;
}

MotionSensor::~MotionSensor()
{
    // for(SmartDevice* device: devices)
    // {
    //     delete device;
    //     device = NULL;
    // }
    devices.clear();
}

void MotionSensor::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

void MotionSensor::removeDevice(SmartDevice *device)
{
   for (auto it = devices.begin(); it != devices.end(); ++it)
    {
        if (*it == device)
        {
            devices.erase(it);
            break;
        }
    }
}

void MotionSensor::notifyDevices()
{

    std::cout<<"Motion has been detected!! \t- notifying devices... \n";
    for (auto device : devices)
    {
        device->update();
    }
}

void MotionSensor::detectMotion()
{
    std::cout<<"~!Motion detected!~"<<std::endl;
    notifyDevices();
}
