#ifndef HOMESECTION_H
#define HOMESECTION_H

#include "Room.h"
#include <iostream>
#include <string>

/**
 * @file HomeSection.h
 * @brief Defines the HomeSection class, which represents a collection of rooms in a specific section of the home.
 * 
 * The HomeSection class acts as a container for multiple rooms and provides methods to manage and control those rooms.
 */
class HomeSection : public SmartDevice {
private:
    std::vector<Room*> rooms; /**< Vector containing pointers to Room objects in this section. */
    std::string secName; 

public:
    /**
     * @brief Constructs a HomeSection object with a specified name.
     * 
     * @param name The name of the home section.
     */
    HomeSection(const std::string& name);

    /**
     * @brief Destructor for the HomeSection class.
     * 
     * Cleans up the rooms contained in the section.
     */
    ~HomeSection();

    /**
     * @brief Adds a room to the home section.
     * 
     * @param room Pointer to the Room object to be added.
     */
    void addRoom(Room* room);

    /**
     * @brief Removes a room from the home section.
     * 
     * @param room Pointer to the Room object to be removed.
     */
    void removeRoom(Room* room);

    /**
     * @brief Displays the rooms in the home section.
     */
    void displayHomeSection();

    /**
     * @brief Gets the name of the home section.
     * 
     * @return The name of the home section.
     */
    std::string getSectionName();

    /**
     * @brief Returns the type of device (HomeSection).
     * 
     * @return A string representing the type of device.
     */
    std::string getDeviceType() override;

    /**
     * @brief Performs an action on all rooms in the section.
     * 
     * Executes a generic action for all rooms contained in the home section.
     */
    void performAction() override;
    

    //
    void update() override;


};

#endif // HOMESECTION_H
