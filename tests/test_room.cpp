#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Room.h"
#include "Light.h"
#include "Thermostat.h"

TEST_CASE("Testing Room Class") {
    // Constructing Room object
    Room room("LivingRoom");

    // Creating devices to add to the room
    Light light("LivingRoomLight", 100, 50);
    Thermostat thermostat("LivingRoomThermostat");

    // Add devices to room
    room.addDevice(&light);  // Using pointers that are properly scoped
    room.addDevice(&thermostat);

}
