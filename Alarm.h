#ifndef ALARM_H
#define ALARM_H

#include <iostream>
#include <string>
#include "SmartDevice.h"
#include "AlarmState.h"
#include "Deactivated.h"


class Alarm : public SmartDevice
{
    private:
    std::string alarmType;
    int loudness;
    std::string security;
    AlarmState*  state;

    public:
    Alarm(std::string typeAlarm, int decibels , const std::string& grade);
    ~Alarm();
    //void performAction() ;
    void performAction() override;
    std::string getDeviceType() override;
    //
std::string getStatus() const ;
    void setStatus(AlarmState* status) ;
    


};
#endif