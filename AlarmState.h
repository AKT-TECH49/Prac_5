#ifndef ALARMSTATE_H
#define ALARMSTATE_H

#include <iostream>
#include <string>

class Alarm;

class AlarmState 
{
    public:
    virtual ~AlarmState() = default;
    //suggest methods please
    virtual void activateAlarm(Alarm* alarm) = 0;
    virtual void deactivateAlarm(Alarm* alarm) = 0;
    virtual std::string toString() const = 0;

};
#endif