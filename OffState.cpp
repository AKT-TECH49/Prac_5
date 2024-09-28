#include "OffState.h"




void OffState::toggle(Light *light)
{
    OnState* newState = new OnState();
    light->setState(newState);
    // delete light;
    std::cout<<"~!LIGHT TURNED ON!~\n";
}

std::string OffState::toString() const
{
     return "Off";
}
