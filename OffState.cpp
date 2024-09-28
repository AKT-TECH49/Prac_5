#include "OffState.h"
#include "OnState.h" 

void OffState::toggle(Light *light)
{ 
    light->setState(new OnState());
    std::cout<<"~!LIGHT TURNED ON!~\n";
}

std::string OffState::toString() const
{
     return "Off";
}
