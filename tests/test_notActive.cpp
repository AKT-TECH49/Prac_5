// for the notAtive (Deactivated Alarm) class
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Deactivated.h"
#include "Alarm.h"

TEST_CASE("notActive functionality") {
    Alarm alarm("Home Alarm", 80, "Grade A");
    notActive deactivatedState;

    // Set the alarm to deactivated state and check the status
    alarm.setStatus(&deactivatedState);
    CHECK(alarm.getStatus() == "Deactivated");

    // Activate the alarm and check the state transition
    deactivatedState.activateAlarm(&alarm);
    CHECK(alarm.getStatus() == "Active");

    // Deactivate the alarm and check the state
    deactivatedState.deactivateAlarm(&alarm);
}
