#include "Deactivated.h"
#include "Activate.h"


void notActive::activateAlarm(Alarm *alarm)
{
    Active* newS = new Active();
    alarm->setStatus(newS);
    std::cout << "Alarm is now Activated."<<alarm->getStatus()<<"SAFETY PRIORITISED -_- \n";
}

void notActive::deactivateAlarm(Alarm *alarm)
{
    std::cout<<"!!Alarm is deActivated!! _-_ \n";
    std::cout<<"State is: "<<alarm->getStatus()<<std::endl;
}

std::string notActive::toString() const
{
    return "Deactivated";
}