#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DefuseAlarm.h"
#include "Alarm.h"
#include "Deactivated.h"
#include "Activate.h"

TEST_CASE("DefuseAlarm functionality") {
    Alarm alarm("Home Alarm", 90, "Grade A");
    DefuseAlarm defuseCmd(&alarm);

    // Test defusing an active alarm
    Active active;
    alarm.setStatus(&active);  // Manually set to Active
    defuseCmd.execute();
    CHECK(alarm.getStatus() == "Deactivated");

    // Test trying to defuse an already deactivated alarm
    defuseCmd.execute();  // Should output "already deactivated"
}
