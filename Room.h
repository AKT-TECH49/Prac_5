#ifndef ROOM_H
#define ROOM_H

#include "SmartDevice.h"
#include <vector>
#include <string>

/**
 * @file Room.h
 * @brief Defines the Room class, which represents a collection of smart devices within a room.
 * 
 * The Room class acts as a container for various smart devices and provides methods to manage, control, and interact with those devices.
 */
class Room : public SmartDevice {
private:
    std::vector<SmartDevice*> devices; /**< Vector containing pointers to smart devices within the room. */
    std::string roomName; 

public:
    /**
     * @brief Constructs a Room object with a specified name.
     * 
     * @param name The name of the room.
     */
    Room(const std::string& name);

    /**
     * @brief Destructor for the Room class.
     * 
     * Cleans up the devices contained in the room.
     */
    ~Room();

    /**
     * @brief Adds a smart device to the room.
     * 
     * @param device Pointer to the SmartDevice to be added to the room.
     */
    void addDevice(SmartDevice* device);

    /**
     * @brief Removes a smart device from the room.
     * 
     * @param device Pointer to the SmartDevice to be removed from the room.
     */
    void removeDevice(SmartDevice* device);

    /**
     * @brief Returns the type of device (Room).
     * 
     * @return A string representing the type of device.
     */
    std::string getDeviceType() override;

    /**
     * @brief Performs an action on all devices in the room.
     * 
     * Executes a generic action for all smart devices contained in the room.
     */
    void performAction() override;

    /**
     * @brief Displays the devices in the room.
     * 
     * @return A string representation of the devices in the room.
     */
    std::string displayRooms();

    /**
     * @brief Gets the name of the room.
     * 
     * @return The name of the room.
     */
    std::string getRoomName() const;

    /**
     * @brief Observer update method.
     * 
     * Updates the room's state and notifies all contained devices of changes.
     */
    void update() override;
};

#endif // ROOM_H
