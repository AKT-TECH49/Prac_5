#include "OnState.h"
#include "OffState.h"


void OnState::toggle(Light *light)
{
    
    light->setState(new OffState());
    std::cout<<"~!LIGHT HAS BEEN TURNED OFF!~\n";
}

std::string OnState::toString() const
{
    return "~!ON!~";
}