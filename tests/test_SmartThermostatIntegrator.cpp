#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ThermoIntegrator.h"

TEST_CASE("SmartThermostatIntegrator class") {
    LegendThermo* thermo = new LegendThermo(); // Assuming LegendThermo is a valid class
    SmartThermostatIntegrator adapter(thermo, "Thermostat Adapter");

    adapter.setTemp(22);
    CHECK(adapter.getTemP() == 22);

    adapter.performAction();
    // Validate temperature adjustment logic in performAction()

    delete thermo; // Clean up
}
