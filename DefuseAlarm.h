#ifndef DEFUSEALARM_H
#define DEFUSEALARM_H

#include "SmartDeviceCommand.h"
#include "Alarm.h"

class DefuseAlarm : public SmartDeviceCommand {
private:
    Alarm* alarm;
public:
    DefuseAlarm(Alarm* alarm);
    virtual~DefuseAlarm();
    void execute() override;
};

#endif // DEFUSEALARM_H
