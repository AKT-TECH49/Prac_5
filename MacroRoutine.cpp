

#include "SmartDeviceCommand.h"
#include "MacroRoutine.h"
#include <vector>

void MacroRoutine::addCommand(SmartDeviceCommand *command)
{
    commands.push_back(command);
}

void MacroRoutine::execute()
{
    for (SmartDeviceCommand *command : commands)
    {
        command->execute();
    }
}

MacroRoutine::~MacroRoutine()
{
    for (SmartDeviceCommand *command : commands)
    {
        delete command;
    }
    // clear the vector after delete commands
    commands.clear();
}
