#ifndef OFFSTATE_H
#define OFFSTATE_H

#include <iostream>
#include <string>

#include "LightState.h"

class OffState : public LightState
{   
    public:
    void toggle(Light* light) override ;
    std::string toString() const override;
};


#endif