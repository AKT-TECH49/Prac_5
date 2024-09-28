#ifndef LIGHTSTATE_H
#define LIGHTSTATE_H    

#include <iostream>
#include <string> 

class Light ;

class LightState
{
    public:
    virtual ~LightState()=default ;
    virtual void toggle(Light*  light) = 0;
    virtual std::string toString() const = 0;
};

#endif