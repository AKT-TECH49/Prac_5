#include "Alarm.h"

Alarm::Alarm(std::string typeAlarm, int decibels, const std::string &grade):SmartDevice(alarmType ,44 )
{
    this->alarmType = typeAlarm;
    this->loudness = decibels;
    this->security = grade;
    state = new notActive();
}

Alarm::~Alarm()
{
    delete state;
}

void Alarm::performAction()
{
    state->activateAlarm(this);
}


std::string Alarm::getDeviceType() 
{
    return alarmType;
}

std::string Alarm::getStatus() const
{
     std::string state_name = state->toString();
    return  state_name;
}

void Alarm::setStatus(AlarmState *status)
{
    delete state;
    this->state = status;
}
