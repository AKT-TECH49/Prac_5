#include "Temperature.h"

Temperature::Temperature(const std::string &name)
{
    this->name = name;
}

Temperature::~Temperature()
{
    // for(SmartDevice* device : devices)
    // {
    //     delete device;
    //     device = NULL;
    // }
    devices.clear();
}

void Temperature::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

void Temperature::removeDevice(SmartDevice *device)
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

void Temperature::notifyDevices()
{
    std::cout<<"Temperature change detected! \t- notifying devices \n";
    for (auto device : devices)
    {
        device->update();
    }
}

void Temperature::detectTemp()
{
    std::cout<<"Interference with Temperature"<<std::endl;
    notifyDevices();
}
