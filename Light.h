#ifndef LIGHT_H
#define LIGHT_H
 
#include <iostream>
#include <string>
#include "SmartDevice.h"
#include "LightState.h"

/**
 * @file Light.h
 * @brief Defines the Light class, which represents a smart light in the home automation system.
 * 
 * This class controls a light, managing its brightness, power, and state through interaction
 * with the LightState interface.
 * 
 * @warning The class assumes ownership of the LightState pointer and is responsible for its deletion.
 * 
 *  @author Mpho_Siminya_u21824241 and Amantle_Temo_u23539764
 *  @version 1.0
 * @todo Add functionality to handle dimming and color-changing lights.
 */
class Light : public SmartDevice {
private:
    int brightness;   /**< The brightness level of the light (0-100). */
    int power;        /**< The power consumption in watts. */
    LightState* state; /**< Pointer to the current state of the light (on/off). */
    std::string name; /**< Name of the light. */

public:
    /**
     * @brief Constructs a Light object with an initial brightness and power rating.
     * 
     * @param lightType The type or name of the light (e.g., "LED").
     * @param initBrightness Initial brightness level (0-100).
     * @param wattz Power consumption in watts.
     */
    Light( const std::string& lightType , int initBrightness, int wattz );

    /**
     * @brief Destructor for the Light class.
     * 
     * Cleans up the dynamically allocated LightState object.
     */
    ~Light();

    /**
     * @brief Gets the current status of the light.
     * 
     * Returns a string representation of the light's current state, including brightness and power.
     * 
     * @return A string describing the light's current status.
     */
    std::string getStatus() const;

    /**
     * @brief Sets the state of the light (on or off).
     * 
     * This method allows changing the state of the light by providing a new LightState object.
     * 
     * @param light Pointer to a new LightState (on/off).
     */
    void setState(LightState* light);

    /**
     * @brief Performs an action based on the current light state.
     * 
     * Invokes the current state’s action on the light (e.g., turning it on or off).
     */
    void performAction() override;

    /**
     * @brief Returns the type of smart device (Light).
     * 
     * @return A string representing the device type.
     */
    std::string getDeviceType() override;

    /**
     * @brief Observer update method.
     * 
     * This method is used to notify the light of changes, allowing it to update its state.
     */
    void update() override;
};

#endif
