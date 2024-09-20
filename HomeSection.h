#ifndef HOMESECTION_H
#define HOMESECTION_H

#include "Room.h"
#include <iostream>
#include <string>

class HomeSection : public SmartDevice
{
    private:
    std::vector<Room*>  rooms;
    std::string secName;

    public:
    HomeSection(const std::string& name);
    ~HomeSection();
    void addRoom(Room* room);
    void removeRoom(Room* room);
    void displayHomeSection();
    std::string getSectionName();
    //
    std::string getDeviceType() override;
    void performAction() override;
    



};
#endif