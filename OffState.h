#ifndef OFFSTATE_H
#define OFFSTATE_H

#include <iostream> 
#include <string>
 
#include "LightState.h"
#include "OnState.h"
#include "Light.h"


class OffState : public LightState
{  
    public:
    // ~OffState();
    void toggle(Light* light) override ;
    std::string toString() const override;
};


#endif