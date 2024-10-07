#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "HomeSection.h"
#include "Room.h"

class MockRoom : public Room {
public:
    MockRoom(const std::string& name) : Room(name) {}
    void performAction() override {}
    std::string getDeviceType() override { return "MockRoomDevice"; }
};

TEST_CASE("HomeSection Basic Functionality") {
    HomeSection homeSection("Living Area");
 
    CHECK(homeSection.getSectionName() == "Living Area");

    MockRoom room1("Room 1");
    MockRoom room2("Room 2");

    homeSection.addRoom(&room1);
    homeSection.addRoom(&room2);

    SUBCASE("Check if rooms are added") {
        homeSection.displayHomeSection();
        CHECK(homeSection.getDeviceType() == "MockRoomDeviceMockRoomDevice");
    }

    SUBCASE("Check if room can be removed") {
        homeSection.removeRoom(&room1);
        CHECK(homeSection.getDeviceType() == "MockRoomDevice");
    }

    SUBCASE("Check if section updates all rooms") {
        homeSection.update();
    }
}
