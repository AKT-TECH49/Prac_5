#include "SmartDeviceCommand.h"
#include "DefuseAlarm.h"
#include "Alarm.h"

DefuseAlarm::DefuseAlarm(Alarm *alarm)
    : alarm(alarm) {}

DefuseAlarm::~DefuseAlarm()
{
    // if(alarm)
    // {
    //     delete alarm;
        alarm = NULL;
    // }
}

void DefuseAlarm::execute()
{
    if (alarm->getStatus() == "Active")
    {
        alarm->setStatus(new notActive()); 
        std::cout << alarm->getDeviceType() << " is now deactivated.\n";
    }
    else
    {
        std::cout << alarm->getDeviceType() << " is already deactivated.\n";
    }
}