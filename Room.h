#ifndef ROOM_H
#define ROOM_H

#include "SmartDevice.h"
#include <vector>
#include <string>

class Room : public SmartDevice {
private:
    std::vector<SmartDevice*> devices;  
    std::string roomName;
public:
    Room(const std::string& name);
    ~Room();
    void addDevice(SmartDevice* device);
    void removeDevice(SmartDevice* device);
    //
    std::string getDeviceType() override; 
    // void performAction() override;

    std::string  displayRooms();
    std::string getRoomName() const;
};

#endif // ROOM_H
