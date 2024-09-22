#ifndef SMARTDEVICECOMMAND_H
#define SMARTDEVICECOMMAND_H

// The Command Interface
class SmartDeviceCommand {
public:
    //virtual SmartDeviceCommand();
    virtual void execute() = 0;
    virtual ~SmartDeviceCommand() {}
};

#endif // SMARTDEVICECOMMAND_H
