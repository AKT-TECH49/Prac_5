#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "UnLockedState.h"
#include "DoorLock.h"

TEST_CASE("Testing UnLockedState Class") {
    // Constructing UnLockedState object
    UnLockedState unlockedState;

    // Creating DoorLock object
    DoorLock door("BackDoor");

    // Applying UnLockedState to door
    door.setState(&unlockedState);

    // Verify status
    CHECK(door.getStatus() == "Door is currently unlocked");
}


    