#include "doctest.h"
#include "LockedState.h"
#include "DoorLock.h"

TEST_CASE("LockedState functionality") {
    DoorLock* door = new DoorLock("Front Door", 1, "High");
    LockedState lockedState;

    SUBCASE("Locked state transitions to unlocked") {
        lockedState.pressButton(door);
        CHECK(door->getStat() == "Unlocked");
    }

    SUBCASE("Locked state string representation") {
        CHECK(lockedState.toString() == "Locked");
    }
}
