#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Alarm.h"
#include "Activate.h"
#include "Deactivated.h"  // Assuming this class exists

TEST_CASE("Alarm class functionality") {
    // Create an Alarm object
    Alarm alarm("HomeSecurity", 90, "Grade A");

    // Test that the alarm starts in a deactivated state
    CHECK(alarm.getStatus() == "Deactivated");

    // Test alarm device type, loudness, and security grade
    CHECK(alarm.getDeviceType() == "HomeSecurity");

    // Test performing action while the alarm is deactivated (should activate it)
    alarm.performAction();
    CHECK(alarm.getStatus() == "Active");

    // Test manually setting the alarm state back to deactivated
    notActive deactivatedState;
    alarm.setStatus(&deactivatedState);
    CHECK(alarm.getStatus() == "Deactivated");

    // Test activating and deactivating the alarm again using state transitions
    Active activeState;
    alarm.setStatus(&activeState);
    CHECK(alarm.getStatus() == "Active");

    alarm.setStatus(&deactivatedState);
    CHECK(alarm.getStatus() == "Deactivated");

    // Test the observer update method (simulate external trigger for alarm)
    alarm.update();  // Should activate the alarm since it was deactivated
    CHECK(alarm.getStatus() == "Active");
}
