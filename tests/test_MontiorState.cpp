#include "doctest.h"
#include "MonitorState.h"
#include "Thermostat.h"

TEST_CASE("MonitorState functionality") {
    Thermostat thermostat;
    MonitorState monitorState;

    SUBCASE("MonitorState transitions to Cold, Mild, or Hot based on temperature") {
        thermostat.setTemperature(17);
        monitorState.read(&thermostat);
        CHECK(thermostat.getState()->toString() == "Cold");

        thermostat.setTemperature(19);
        monitorState.read(&thermostat);
        CHECK(thermostat.getState()->toString() == "Mild");

        thermostat.setTemperature(30);
        monitorState.read(&thermostat);
        CHECK(thermostat.getState()->toString() == "Hot");
    }
}
