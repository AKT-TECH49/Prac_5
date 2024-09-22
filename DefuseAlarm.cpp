#include "SmartDeviceCommand.h"
#include "DefuseAlarm.h"
#include "Alarm.h"

DefuseAlarm::DefuseAlarm(Alarm *alarm) 
    : alarm(alarm) {}


DefuseAlarm::~DefuseAlarm() {
    // Optional: Destructor implementation
}

void DefuseAlarm::execute()
{
    if (alarm->getStatus() != "Deactivated")
    {
        alarm->setStatus(new notActive()); // Change the state to deactivated
        std::cout << alarm->getDeviceType() << " is now deactivated.\n";
    }
    else
    {
        std::cout << alarm->getDeviceType() << " is already deactivated.\n";
    }
}