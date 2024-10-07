#include "doctest.h"
#include "MildTemp.h"
#include "Thermostat.h"

TEST_CASE("MildState behavior") {
    Thermostat thermostat;
    MildState mildState;

    SUBCASE("Initial state is Mild") {
        CHECK(mildState.toString() == "Mild");
        CHECK(mildState.isMild() == true);
        CHECK(mildState.isCold() == false);
        CHECK(mildState.isHot() == false);
    }

    SUBCASE("Reading mild state") {
        mildState.read(&thermostat);
        CHECK(mildState.toString() == "Mild");
    }
}
