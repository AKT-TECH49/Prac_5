#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "TurnOffAllLights.h"
#include "Room.h"
#include "Light.h"

TEST_CASE("Testing TurnOffAllLights Command") {
    // Creating Room and Light objects
    Light* livingRoomLight = new Light("Living Room Light", 100, 60);

    // Execute TurnOffAllLights command
    TurnOffAllLights* turnOffLightsCmd = new TurnOffAllLights(livingRoomLight);
    //turnOffCommand->execute();

    // Verify that all lights in the room are turned off
    CHECK(livingRoomLight->getStatus() == "Light is currently off");
}
