#include "SmartDeviceCommand.h"
#include "MacroRoutine.h"
#include <vector>

void MacroRoutine::addCommand(SmartDeviceCommand *command)
{
    commands.push_back(command);
}

MacroRoutine::~MacroRoutine()
{
    for (auto command : commands)
    {
        delete command;
    }
    commands.clear();
}

void MacroRoutine::removeCommand(SmartDeviceCommand *cmd)
{
    for (auto it = commands.begin(); it != commands.end(); ++it)
    {
       
        if (*it == cmd)
        {   
            commands.erase(it);
            break;
        }
    }
}

void MacroRoutine::execute()
{
    for (SmartDeviceCommand *command : commands)
    {
        command->execute();
    }
}
