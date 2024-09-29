#include "OnState.h"


// OnState::~OnState()
// {
//     delete newState;
// }

void OnState::toggle(Light *light)
{
   OffState* newState = new OffState();
    light->setState(newState);
    std::cout<<"~!LIGHT HAS BEEN TURNED OFF!~\n";
}

std::string OnState::toString() const
{
    return "~!ON!~";
}