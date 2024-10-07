#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "IdleState.h"
#include "Thermostat.h"

TEST_CASE("Testing IdleState Class") {
    // Constructing IdleState object
    IdleState idleState;

    // Creating Thermostat object
    Thermostat thermo("HallwayThermostat");

    // Applying IdleState
    thermo.setState(&idleState);

    // Verify status
    CHECK(thermo.getStatus() == "Thermostat is in idle state");
}
