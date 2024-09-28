#ifndef STATE_H
#define STATE_H

#include <string>

class SmartDevice;

/**
 * @file State.h
 * @brief Defines the abstract State class for managing device states in a smart home system.
 * 
 * The State class represents the abstract interface for various states
 * of a smart device. It is part of the State design pattern.
 */
class State {
public:
    /**
     * @brief Virtual destructor for the State class.
     * 
     * Ensures proper cleanup of derived state classes when a State object is destroyed.
     */
    virtual ~State() {}

    /**
     * @brief Pure virtual function to get the status of the current state.
     * 
     * This method must be implemented by derived classes to return the current status of the device.
     * 
     * @return A string representing the status of the state (e.g., "On", "Off").
     */
    virtual std::string getStatus() = 0;

    /**
     * @brief Pure virtual function to toggle the smart device to an "On" state.
     * 
     * This method must be implemented by derived state classes to define how a device switches to the "On" state.
     * 
     * @param device A pointer to the SmartDevice that is affected by this state change.
     */
    virtual void toggleOn(SmartDevice* device) = 0;

    /**
     * @brief Pure virtual function to toggle the smart device to an "Off" state.
     * 
     * This method must be implemented by derived state classes to define how a device switches to the "Off" state.
     * 
     * @param device A pointer to the SmartDevice that is affected by this state change.
     */
    virtual void toggleOff(SmartDevice* device) = 0;
};

#endif // STATE_H
