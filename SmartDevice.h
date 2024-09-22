#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <iostream>
#include <string>
#include "LightState.h"
#include "DoorLState.h"
#include "ThermoState.h"



class SmartDevice
{
    private: 
    std::string name;
    int id;


    public:
    virtual ~SmartDevice() = default;
    SmartDevice(const std::string& name , int typeId); 
    //       
    virtual std::string getDeviceType() = 0; 
    virtual void performAction()=0;
    //
    std::string getName() const ;
    int getId() const ;

    //
    virtual void update() = 0;
 
};

#endif