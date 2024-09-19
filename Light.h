#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <string>
#include "SmartDevice.h"
#include "LightState.h"

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
    void performAction();
    //
    std::string getDeviceType() override;

};

#endif 