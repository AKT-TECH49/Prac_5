#include "Room.h"
#include <iostream>
#include <algorithm>

Room::Room(const std::string &name) : SmartDevice(name, 00)
{
    this->roomName = name;
}

Room::~Room()
{
    for (SmartDevice *device : devices)
    {
        delete device;
    }
}

void Room::addDevice(SmartDevice *device)
{
    if (device)
    {
        devices.push_back(device);
    }
    else
    {
        return;
    }
}

void Room::removeDevice(SmartDevice *device)
{
    // remove device
    if (device)
    {
        auto it = std::find(devices.begin(), devices.end(), device);
        if (it != devices.end())
        {
            devices.erase(it);
            std::cout << "Device removed from: " << roomName << std::endl;
        }
        else
        {
            std::cout << "Device not found in the Room." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid ." << std::endl;
    }
}

std::string Room::getDeviceType()
{
   std::cout << "All the Device types in the room: " << std::endl;
   std::string deviceType;

    for (SmartDevice* device : devices)
    {
        deviceType += device->getDeviceType() + " | ";
    }

    if (deviceType.empty())
    {
        return "No devices in the room.";
    }
    
    
    return deviceType; 
}

void Room::performAction()
{
    for (SmartDevice* device : devices)
    {
        device->performAction();
    }
}

std::string Room::displayRooms()
{
    std::string rooms;
    std::cout << "The devices in the " << roomName << "are : " << std::endl;
    for (SmartDevice *device : devices)
    {
        rooms += device->getDeviceType() + " | ";
    }
    if (rooms.empty())
    {
        std::cout<<"No devices"<<std::endl;
    }

    return rooms;
}

std::string Room::getRoomName() const
{
    return roomName;
}
