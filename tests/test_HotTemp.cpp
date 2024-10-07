#include "doctest.h"
#include "HotTemp.h"
#include "Thermostat.h"

TEST_CASE("HotState Functionality") {
    Thermostat thermo;
    HotState hotState;

    CHECK(hotState.toString() == "Hot");

    SUBCASE("Check hot state behavior") {
        CHECK(hotState.isHot() == true);
        CHECK(hotState.isCold() == false);
        CHECK(hotState.isMild() == false);
    }
}
 