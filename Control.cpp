#include "Control.h"

Control::~Control()
{
    for (auto sensor : sensors)
    {
        delete sensor;
        sensor = NULL;
    }

    for (auto device : devices)
    {
        delete device;
        device = NULL;
    }
}

void Control::addSensor(Sensor *sensor)
{
    sensors.push_back(sensor);
}

void Control::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

void Control::notifySpecificDevice(SmartDevice *device)
{
    device->update();
}
