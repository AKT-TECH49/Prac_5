#ifndef STATE_H
#define STATE_H

#include <string>

class SmartDevice;

class State {
public:
    virtual ~State() {}
    virtual std::string getStatus() = 0;
    virtual void toggleOn(SmartDevice* device) = 0;
    virtual void toggleOff(SmartDevice* device) = 0;
};

#endif
