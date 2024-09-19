#ifndef DEACTIVATE_H
#define DEACTIVATE_H

#include <iostream>
#include <string>
#include "AlarmState.h"
#include "Alarm.h"

class notActive : public AlarmState
{
    public:
    //implement suggested methods in AlarmState
    void activateAlarm(Alarm* alarm) override;
    void deactivateAlarm(Alarm* alarm) override;
    std::string toString() const override;
};


#endif