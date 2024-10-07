#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Light.h"
#include "OnState.h"
#include "OffState.h"

TEST_CASE("Light Test") {
    // Setup the light object
    Light *light = new Light("TestLight", 100, 50);

    // Check initial properties
    CHECK(light->getDeviceType() == "TestLight");
    CHECK(light->getStatus() == "Light is currently off");

    // Perform Action and Check
    light->performAction();
    CHECK(light->getStatus() == "Light is currently on");

    // Manually set states
    OnState* on = new OnState();
    OffState* off = new OffState();
    
    // Set OnState and check status
    light->setState(on);
    CHECK(light->getStatus() == "Light is currently on");

    // Set OffState and check status
    light->setState(off);
    CHECK(light->getStatus() == "Light is currently off");

    // Cleanup
    delete on;
    delete off;
    delete light;
}
