#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Activate.h"
#include "Alarm.h"  // Include the Alarm class

TEST_CASE("Active class functionality with Alarm") {
    // Create an Alarm object
    Alarm alarm("HomeSecurity", 90, "Grade A");

    // Test that the alarm starts in a deactivated state
    CHECK(alarm.getStatus() == "Deactivated");

    // Create an Active state object
    Active activeState;

    // Test activating the alarm
    activeState.activateAlarm(&alarm);
    CHECK(alarm.getStatus() == "Active");

    // Test deactivating the alarm
    activeState.deactivateAlarm(&alarm);
    CHECK(alarm.getStatus() == "Deactivated");
}
