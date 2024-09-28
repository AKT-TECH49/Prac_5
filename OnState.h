#ifndef ONSTATE_H
#define ONSTATE_H

#include <iostream>
#include <string>

#include "LightState.h"
#include "OffState.h"
#include "Light.h"


class OnState : public LightState
{   
    public:
    // ~OnState();
    void toggle(Light* light) override ;
    std::string toString() const override;

};


#endif