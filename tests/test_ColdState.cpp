#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ColdTemp.h"
#include "Thermostat.h"

TEST_CASE("ColdState functionality") {
   Thermostat thermo;
    ColdState coldState;

    CHECK(coldState.toString() == "Cold");

    SUBCASE("Check cold state behavior") {
        CHECK(coldState.isHot() == true);
        CHECK(coldState.isCold() == false);
        CHECK(coldState.isMild() == false);
    }
}
