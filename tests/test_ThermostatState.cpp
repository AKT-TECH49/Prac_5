#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ThermoState.h"
#include "IdleState.h"
#include "MonitorState.h"

TEST_CASE("ThermostatState class - IdleState behavior") {
    ThermostatState* idleState = new IdleState();
    
    CHECK(idleState->isCold() == false);
    CHECK(idleState->isHot() == false);
    CHECK(idleState->isMild() == false);

    CHECK(idleState->toString() == "Idle");

    delete idleState; // Clean up
}

TEST_CASE("ThermostatState class - MonitorState behavior") {
    ThermostatState* monitorState = new MonitorState();

    CHECK(monitorState->isCold() == false);
    CHECK(monitorState->isHot() == false);
    CHECK(monitorState->isMild() == false);

    CHECK(monitorState->toString() == "Monitoring");

    delete monitorState; // Clean up
}
