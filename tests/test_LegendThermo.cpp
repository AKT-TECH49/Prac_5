#include "doctest.h"
#include "LegendThermo.h"

TEST_CASE("LegendThermo Basic Functionality") {
    LegendThermo thermostat;

    SUBCASE("Initial temperature should be 19°C") {
        CHECK(thermostat.readTemperature() == 19);
    }

    SUBCASE("Temperature adjustment") {
        thermostat.adjustTemperature(25);
        CHECK(thermostat.readTemperature() == 25);
    }
}
