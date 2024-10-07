#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MacroRoutine.h"
#include "TurnOffAllLights.h"
#include "LockAllDoors.h"

TEST_CASE("Testing MacroRoutine Class") {
    // Creating MacroRoutine object
    MacroRoutine* goodnightRoutine = new MacroRoutine();
    MacroRoutine* goodnightRoutine2 = new MacroRoutine();

    // Creating commands
    Light* livingRoomLight = new Light("Living Room Light", 100, 60); 
    DoorLock* frontDoor = new DoorLock("Front Door", 1, "High");

    // Add commands to routine
    goodnightRoutine->addCommand(livingRoomLight);
    goodnightRoutine2->addCommand(frontDoor);

    // Execute routine
    goodnightRoutine->execute();
    goodnightRoutine2->execute();
}
