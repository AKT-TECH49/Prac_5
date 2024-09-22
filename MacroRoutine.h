#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include "SmartDeviceCommand.h"
#include <vector>

// MacroRoutine Class
class MacroRoutine
{
private:
    std::vector<SmartDeviceCommand *> commands;

public:
    void addCommand(SmartDeviceCommand *command);
    void execute();
    ~MacroRoutine();
};

#endif // MACROROUTINE_H
