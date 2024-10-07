// this test, tests for the the OffState and the OnState at the same time.
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OffState.h"
#include "OnState.h"
#include "Light.h"

TEST_CASE("Testing OffState and OnState toggle behavior") {
    Light *light = new Light("Living Room Light", 100, 60);

    SUBCASE("Toggle from Off to On") {
        OffState* off = new OffState();
        light->setState(off);
        CHECK(light->getStatus() == "Off");
        CHECK(light->getStatus() == "~!ON!~");
    }

    SUBCASE("Toggle from On to Off") {
        OnState* on = new OnState();
        light->setState(on);
        CHECK(light->getStatus() == "~!ON!~");
        CHECK(light->getStatus() == "Off");
    }
}
