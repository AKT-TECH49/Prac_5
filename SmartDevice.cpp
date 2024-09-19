#include "SmartDevice.h"

SmartDevice::SmartDevice(const std::string &name , int typeID)
{
    this->name = name;
    this->id = typeID;
}

std::string SmartDevice::getName() const
{
    return std::string();
}
