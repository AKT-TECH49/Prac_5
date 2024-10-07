#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LockAllDoors.h"
#include "DoorLock.h"
#include "LockedState.h"

TEST_CASE("LockAllDoors command execution") {
    DoorLock door("Front Door", 1, "High");
    
    SUBCASE("Lock door when unlocked") {
        door.setStat(new UnlockedState());
        LockAllDoors lockCommand(&door);
        lockCommand.execute();
        CHECK(door.getStat() == "Locked");
    }

    SUBCASE("Try to lock door when already locked") {
        door.setStat(new LockedState());
        LockAllDoors lockCommand(&door);
        lockCommand.execute();
        CHECK(door.getStat() == "Locked");
    }
}
