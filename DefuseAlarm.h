#ifndef DEFUSEALARM_H
#define DEFUSEALARM_H

#include "SmartDeviceCommand.h"
#include "Alarm.h"

/**
 * @file DefuseAlarm.h
 * @brief Concrete command to defuse the alarm in a smart home automation system.
 * 
 * This class implements the Command interface and provides the execute method to defuse an alarm.
 * 
 *  
 * @author Mpho_Siminya_u21824241 and Amantle_Temo_u23539764
 *  @version 1.0
 */
class DefuseAlarm : public SmartDeviceCommand {
private:
    Alarm* alarm; /**< Pointer to the Alarm object being controlled. */

public:
    /**
     * @brief Constructs a DefuseAlarm command with a specific Alarm.
     * 
     * @param alarm Pointer to the Alarm object to be defused.
     */
    DefuseAlarm(Alarm* alarm);

    /**
     * @brief Destructor for the DefuseAlarm command.
     */
      ~DefuseAlarm();

    /**
     * @brief Executes the command to defuse the alarm.
     */
    void execute() override;
};

#endif // DEFUSEALARM_H
