#include "doctest.h"
#include "Motion.h"
#include "SmartDevice.h"

class MockDevice : public SmartDevice {
public:
    bool updated = false;

    void update() override {
        updated = true;
    }

    std::string getDeviceType() override {
        return "MockDevice";
    }
};

TEST_CASE("MotionSensor functionality") {
    MotionSensor motionSensor("Living Room Motion Sensor");
    MockDevice device1, device2;

    SUBCASE("Add and notify devices on motion detection") {
        motionSensor.addDevice(&device1);
        motionSensor.addDevice(&device2);

        motionSensor.detectMotion();

        CHECK(device1.updated == true);
        CHECK(device2.updated == true);
    }

    SUBCASE("Remove device and detect motion") {
        motionSensor.addDevice(&device1);
        motionSensor.removeDevice(&device1);

        motionSensor.detectMotion();

        CHECK(device1.updated == false); // Device should not be notified after removal
    }
}
