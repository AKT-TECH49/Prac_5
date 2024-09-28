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
 * @todo Add functionality to handle dimming and color-changing lights.
 */
class Light : public SmartDevice {
private:    
    int brightness;   
    int power;
    LightState* state; 
    std::string name;
        
    public:
    Light( const std::string& lightType , int initBrightness, int wattz ) ;
    ~Light() ;
    //Actions
    std::string getStatus() const ;
    void setState(LightState * light);

    //will invoke the states
   // void performAction();
     void performAction() override;
    //
    std::string getDeviceType() override;


      //observer
      void update() override;


};

#endif
