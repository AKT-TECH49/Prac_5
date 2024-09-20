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
    this->state = status;
}

void Alarm::update()
{
    if(state->toString() == "Deactivated")
    {
        state->activateAlarm(this);
        std::cout<<"Alarm is activated and alerted!!!"<<std::endl;
    }
    else
    {
        std::cout<<"Alarm is already Active and is now ALERTED!!!"<<std::endl;
    }
}
