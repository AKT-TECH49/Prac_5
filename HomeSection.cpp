#include "HomeSection.h"
#include <algorithm>
#include <iostream>


HomeSection::HomeSection(const std::string &name):SmartDevice(name , 00)
{
    this->secName = name;
}


HomeSection::~HomeSection()
{
    for(Room* room : rooms)
    {
        delete room;
    }
}

void HomeSection::addRoom(Room *room)
{
    if(room)
    {
        rooms.push_back(room);
    }
}

void HomeSection::removeRoom(Room *room)
{
      if (room)
    {
        auto it = std::find(rooms.begin(), rooms.end(), room);
        if (it != rooms.end())
        {
            rooms.erase(it); 
            std::cout << "Room removed from: "<<secName<< std::endl;
        }
        else
        {
            std::cout << "room not found in the homeSection" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid room." << std::endl;
    }
}

void HomeSection::displayHomeSection()
{

    for(Room* room : rooms)
    {
        std::cout<<"Rooms in the section: "<<secName<<std::endl;
        std::cout<<room->getRoomName()<<"| \n";
    }
}

std::string HomeSection::getSectionName()
{
    return secName;
}

std::string HomeSection::getDeviceType()
{
    std::string roomsDeTypes;
   for(Room* room : rooms)
   {
     roomsDeTypes += room->getDeviceType();
   } 
   if(roomsDeTypes.empty())
   {
     return "No rooms or no rooms with devices";
   }
   return roomsDeTypes;
   
}

void HomeSection::performAction()
{
    for(Room* room : rooms) 
    {
        room->performAction();
    }
}
