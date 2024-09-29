#include "SmartDevice.h"

SmartDevice::SmartDevice( int typeID)
{
    this->id = typeID;
}

int SmartDevice::getId()
{
    return id;
}