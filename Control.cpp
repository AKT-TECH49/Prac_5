#include "Control.h"

Control::~Control()
{
    for (auto sensor : sensors)
    {
        delete sensor;
        sensor = NULL;
    }

    sensors.clear();

    for (auto device : devices)
    {
        delete device;
        device = NULL;
    }
    devices.clear();
}

void Control::addSensor(Sensor *sensor)
{
    sensors.push_back(sensor);
}

void Control::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

void Control::removeSensor(Sensor *sensor)
{
    for (auto it = sensors.begin(); it != sensors.end(); ++it)
    {
        if (*it == sensor)
        {
            //delete 
            sensors.erase(it);
            break;
        }
    }
}

void Control::removeDevice(SmartDevice *device)
{
    for (auto it = devices.begin(); it != devices.end(); ++it)
    {
        //remove
        if (*it == device)
        {
            devices.erase(it);
            break;
        }
    }
}

void Control::notifySpecificDevice(SmartDevice *device)
{
    device->update();
}
