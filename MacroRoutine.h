#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include "SmartDeviceCommand.h"
#include <vector>

/**
 * @file MacroRoutine.h
 * @brief MacroRoutine class to execute a sequence of commands in a smart home automation system.
 * 
 * This class allows the user to queue multiple commands and execute them sequentially.
 * 
 * @warning Ensure proper memory management of the SmartDeviceCommand pointers in the vector.
 */
class MacroRoutine {
private:
    std::vector<SmartDeviceCommand*> commands; /**< Vector storing pointers to SmartDeviceCommand objects. */

public:
    /**
     * @brief Adds a command to the macro routine.
     * 
     * @param command Pointer to the SmartDeviceCommand object to be added.
     */
    void addCommand(SmartDeviceCommand* command);

    /**
     * @brief Executes all commands in the macro routine.
     */
    void execute();

    /**
     * @brief Destructor for the MacroRoutine class.
     * 
     * Responsible for cleaning up any dynamically allocated SmartDeviceCommand objects.
     */
    ~MacroRoutine();
};

#endif // MACROROUTINE_H
