#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <iostream>
#include <string>
#include "AlarmState.h"

class Active : public AlarmState
{
    public:
    ~Active() = default;
    void activateAlarm(Alarm* alarm) override;
    void deactivateAlarm(Alarm* alarm) override;
    std::string toString() const override;

};


#endif