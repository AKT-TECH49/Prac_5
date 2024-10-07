#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DoorLock.h"
#include "LockedState.h"
#include "UnLockedState.h"

TEST_CASE("Testing DoorLock Class") {
    // Constructing DoorLock object
    DoorLock doorLock("Front Door", 1, "High");

    // Verify default state (Unlocked)
    CHECK(doorLock.getDeviceType() == "MainDoor");
    CHECK(doorLock.getStat() == "Door is currently unlocked");

    // Perform action to lock the door
    doorLock.performAction();
    CHECK(doorLock.getStat() == "Door is currently locked");

    // Set to UnLockedState and verify
    doorLock.setStat(new UnlockedState());
    CHECK(doorLock.getStat() == "Door is currently unlocked");
}
