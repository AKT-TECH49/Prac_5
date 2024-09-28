#include "Activate.h"
#include "Deactivated.h"

void Active::activateAlarm(Alarm *alarm)
{
    std::cout<<"Alarm is active!!.\n";
   std::cout<<"State is: " << alarm->getStatus();
}

void Active::deactivateAlarm(Alarm *alarm)
{
    alarm->setStatus(new notActive());
    std::cout<<"Alarm is deactivated!!.\n";
}


std::string Active::toString() const
{
    return "Active";
}
