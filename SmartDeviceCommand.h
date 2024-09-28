#ifndef SMARTDEVICECOMMAND_H
#define SMARTDEVICECOMMAND_H

/**
 * @file SmartDeviceCommand.h
 * @brief Command interface for controlling smart devices in a smart home automation system.
 * 
 * The SmartDeviceCommand class defines the common interface for all concrete commands that control smart devices.
 */
class SmartDeviceCommand {
public:
    /**
     * @brief Executes the command.
     * 
     * This pure virtual function must be implemented by all concrete command classes.
     */
    virtual void execute() = 0;

    /**
     * @brief Virtual destructor for SmartDeviceCommand.
     * 
     * Ensures proper cleanup of derived classes.
     */
    virtual ~SmartDeviceCommand() {}
};

#endif // SMARTDEVICECOMMAND_H
