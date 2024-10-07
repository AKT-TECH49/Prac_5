// added features to be fancy
#include <thread>
#include <chrono>

// base needed for all the patterns
#include "SmartDevice.h"
#include "Room.h"
#include "HomeSection.h"

// base needed for all the patterns
#include "Light.h"
#include "Thermostat.h"
#include "Alarm.h"
#include "DoorLock.h"

// needed for the state design pattern
#include "LightState.h"
#include "ThermoState.h"
#include "AlarmState.h"
#include "DoorLState.h"

// needed for the state design pattern
#include "OnState.h"
#include "OffState.h"
#include "IdleState.h"
#include "MonitorState.h"
#include "ColdTemp.h"
#include "MildTemp.h"
#include "HotTemp.h"
#include "Deactivated.h"
#include "Activate.h"
#include "UnLockedState.h"
#include "LockedState.h"
//
#include "LegendThermo.h"
#include "ThermoIntegrator.h"
//
#include "Sensor.h"
#include "Motion.h"
#include "Temperature.h"
#include "Control.h"

// needed for the command design pattern
#include "TurnOffAllLights.h"
#include "LockAllDoors.h"
#include "MacroRoutine.h"
#include "DefuseAlarm.h"
//#include "SwitchThermo.h"

#include <iostream>
#include <string>

// Add color codes for terminal output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"

// Emojis for a friendly UX
#define LIGHT_EMOJI "\U0001F4A1"
#define LOCK_EMOJI "\U0001F512"
#define THERMO_EMOJI "\U0001F321"
#define ALARM_EMOJI "\U0001F6A8"
#define SENSOR_EMOJI "\U0001F50C"
#define EXIT_EMOJI "\U0000274C"

// Test for component 1:
void TestComponent1();
// Test for component 2:
void TestComponent2();
// Test for component 2:
void TestComponent3();
// Test for component 4:
void TestComponent4();
// Function to display the menu
void displayMenu();
// This is for the loading bar
void displayLoadingBar();
// drawing the actual loading bar 
void drawLoadingBar(int);

int main()
{
    int choice = 0;

    while (true)
    {
        displayLoadingBar();
        drawLoadingBar(30);
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << YELLOW << "\nRunning " << LIGHT_EMOJI << " Test Component 1...\n"
                      << RESET;
            TestComponent1();
            break;
        case 2:
            std::cout << YELLOW << "\nRunning " << LOCK_EMOJI << " Test Component 2...\n"
                      << RESET;
            TestComponent2();
            break;
        case 3:
            std::cout << YELLOW << "\nRunning " << SENSOR_EMOJI << " Test Component 3...\n"
                      << RESET;
            TestComponent3();
            break;
        case 4:
            std::cout << YELLOW << "\nRunning " << THERMO_EMOJI << " Test Component 4...\n"
                      << RESET;
            TestComponent4();
            break;
        case 5:
            std::cout << RED << "Exiting..." << EXIT_EMOJI << "\n"
                      << RESET;
            return 0;
        default:
            std::cout << RED << "Invalid choice. Please select a valid option.\n"
                      << RESET;
        }
    }
}

void displayMenu()
{
    std::cout << BLUE << BOLD;
    std::cout << "\n==================================================\n";
    std::cout << "=== Smart Home Automation System Demo ===\n";
    std::cout << "==================================================\n";
    std::cout << RESET;
    std::cout << GREEN << "1. " << LIGHT_EMOJI << " Test Component 1: Smart Devices and State Management\n";
    std::cout << GREEN << "2. " << LOCK_EMOJI << " Test Component 2: Legacy Device Integration\n";
    std::cout << GREEN << "3. " << SENSOR_EMOJI << " Test Component 3: Automation of Smart Device Control\n";
    std::cout << GREEN << "4. " << THERMO_EMOJI << " Test Component 4: Sensor Observations and Notifications\n";
    std::cout << RED << "5. " << EXIT_EMOJI << " Exit\n"
              << RESET;
    std::cout << BLUE << "==================================================\n"
              << RESET;
    std::cout << "Please select an option (1-5): ";
}

void displayLoadingBar()
{
    std::cout << "\033[1;33m";
    std::cout << "========================\n";
    std::cout << "\033[1;33m";
    std::cout << "   🔒 Smart Home Automation System 🔒  \n";
    std::cout << "========================\n";
}


void drawLoadingBar(int length)
{
    std::cout << "\nLoading: [";
    for (int i = 0; i <= length; ++i)
    {
        std::cout << "=";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << "] Done!\n" << std::endl;
}

void TestComponent1()
{
    HomeSection *sec1 = new HomeSection("Ground_Floor");
    Room *livingRoom = new Room("LivingRoom");

    Light *light1 = new Light("LedLight", 75, 10);
    DoorLock *doorL1 = new DoorLock("DoorLock", 2, "Grade2");
    Thermostat *thermo1 = new Thermostat("ThermoStat");
    Alarm *alarm1 = new Alarm("Alarm1", 90, "grade1");

    std::cout << CYAN << "\n"
              << LIGHT_EMOJI << " Device: " << light1->getDeviceType() << " - " << light1->getStatus() << "\n";
    std::cout << LOCK_EMOJI << " Device: " << doorL1->getDeviceType() << " - " << doorL1->getStat() << "\n";
    std::cout << THERMO_EMOJI << " Device: " << thermo1->getDeviceType() << " - " << thermo1->getStatus() << "\n";
    std::cout << ALARM_EMOJI << " Device: " << alarm1->getDeviceType() << " - " << alarm1->getStatus() << "\n";

    std::cout << "\n"
              << BOLD << "LETS PLAY!!!!\n"
              << RESET;
    light1->performAction();
    doorL1->performAction();
    thermo1->performAction();
    alarm1->performAction();

    std::cout << CYAN << LIGHT_EMOJI << " Updated Light Status: " << light1->getStatus() << "\n";
    std::cout << LOCK_EMOJI << " Updated Lock Status: " << doorL1->getStat() << "\n";
    std::cout << THERMO_EMOJI << " Updated Thermo Status: " << thermo1->getStatus() << "\n";
    std::cout << ALARM_EMOJI << " Updated Alarm Status: " << alarm1->getStatus() << "\n"
              << RESET;
}

void TestComponent2()
{
    std::cout << "\n🛠️  =================== Testing Component 2: Legacy Device Integration =================== 🛠️\n";

    // =========== Testing the Lights Command =============
    std::cout << "💡 Testing the Lights Command...\n";
    Light *livingRoomLight = new Light("Living Room Light", 100, 60);                                   // Brightness = 100, Power = 60W
    std::cout << "Initial state of the light: \033[32m" << livingRoomLight->getStatus() << "\033[0m\n"; // Green text

    // Create the TurnOffAllLights command
    TurnOffAllLights *turnOffLightsCmd = new TurnOffAllLights(livingRoomLight);

    // Create a macro routine for Goodnight
    MacroRoutine goodnightRoutine;
    goodnightRoutine.addCommand(turnOffLightsCmd);

    // Execute the Goodnight Routine
    std::cout << "\n🌙 Executing Goodnight Routine:\n";
    goodnightRoutine.execute();

    // Check the final state of the light
    std::cout << "\nFinal state of the light: \033[31m" << livingRoomLight->getStatus() << "\033[0m\n"; // Red text

    // Create a GoodMorningRoutine (reverses Goodnight actions)
    MacroRoutine goodMorningRoutine;
    // goodMorningRoutine.addCommand(new TurnOnAllLights(livingRoomLight)); // Revert lights to On

    // Execute the GoodMorning Routine
    std::cout << "\n☀️ Executing Good Morning Routine:\n";
    goodMorningRoutine.execute();
    std::cout << "State of the light after Good Morning routine: \033[32m" << livingRoomLight->getStatus() << "\033[0m\n";

    // =========== Testing the Door Lock Command =============
    std::cout << "\n🚪 Testing the Door Lock Command...\n";
    DoorLock *frontDoor = new DoorLock("Front Door", 1, "High");
    DoorLock *backDoor = new DoorLock("Back Door", 1, "Medium");

    // Create commands to lock each door (Goodnight)
    SmartDeviceCommand *lockFrontDoor = new LockAllDoors(frontDoor);
    SmartDeviceCommand *lockBackDoor = new LockAllDoors(backDoor);

    // Add commands to the Goodnight routine
    goodnightRoutine.addCommand(lockFrontDoor);
    goodnightRoutine.addCommand(lockBackDoor);

    // Execute the Goodnight routine
    std::cout << "\n🌙 Executing Goodnight Routine:\n";
    goodnightRoutine.execute();

    // Check the final state of the doors
    std::cout << "Final state of front door: \033[31m" << frontDoor->getStat() << "\033[0m\n"; // Red text
    std::cout << "Final state of back door: \033[31m" << backDoor->getStat() << "\033[0m\n";   // Red text

    // Execute the GoodMorning Routine
    std::cout << "\n☀️ Executing Good Morning Routine:\n";
    goodMorningRoutine.execute();
    std::cout << "State of front door after Good Morning routine: \033[32m" << frontDoor->getStat() << "\033[0m\n";
    std::cout << "State of back door after Good Morning routine: \033[32m" << backDoor->getStat() << "\033[0m\n";

    // =========== Testing the Defuse/Activate Alarm Command =============
    std::cout << "\n🚨 Testing the Alarm Command...\n";
    Alarm *livingRoomAlarm = new Alarm("Living Room Alarm", 80, "High");
    DefuseAlarm *defuseLivingRoomAlarm = new DefuseAlarm(livingRoomAlarm);

    // Create a macro routine for Goodnight
    MacroRoutine goodnightRoutine3;
    goodnightRoutine3.addCommand(defuseLivingRoomAlarm);

    // Execute the Goodnight Routine
    std::cout << "🌙 Executing Goodnight Routine:\n";
    goodnightRoutine3.execute();

    // Execute the Good Morning Routine
    std::cout << "\n☀️ Executing Good Morning Routine:\n";
    goodMorningRoutine.execute();
    std::cout << "State of alarm after Good Morning routine: \033[32m" << livingRoomAlarm->getStatus() << "\033[0m\n";

    // // =========== Testing the Switch Thermostat Command =============
    // std::cout << "\n🌡️  Testing the Thermostat Command...\n";
    // Thermostat *livingRoomThermo = new Thermostat("Living Room Thermostat"); // Initial temp of 20°C

    // SmartDeviceCommand *switchToHot = new SwitchThermo(livingRoomThermo, 28);  // Setting to 28°C
    // SmartDeviceCommand *switchToCold = new SwitchThermo(livingRoomThermo, 15); // Setting to 15°C

    // // Add thermostat settings to Goodnight and GoodMorning routines
    // goodnightRoutine.addCommand(switchToCold);  // Set to Cold in Goodnight Routine
    // goodMorningRoutine.addCommand(switchToHot); // Set to Hot in GoodMorning Routine

    // // Execute the routines
    // std::cout << "\n🌙 Executing Goodnight Routine for Thermostat:\n";
    // goodnightRoutine.execute();
    // std::cout << "Thermostat temperature after Goodnight routine: \033[34m" << livingRoomThermo->getStatus() << "\033[0m\n"; // Blue text

    // std::cout << "\n☀️ Executing Good Morning Routine for Thermostat:\n";
    // goodMorningRoutine.execute();
    // std::cout << "Thermostat temperature after Good Morning routine: \033[31m" << livingRoomThermo->getStatus() << "\033[0m\n"; // Red text
}

void TestComponent3()
{
    std::cout << "\n📟  =================== Testing Component 3: Automation of Smart Device Control =================== 📟\n";
    std::cout << "\n🛠️ Working with the Legacy Thermostat...\n";

    LegendThermo oldThermo;
    SmartThermostatIntegrator ThermoI(&oldThermo, "ThermoStat");
    std::cout << "\nCurrent Temp: \033[34m" << ThermoI.getTemP() << "\033[0m\n"; // Blue text

    ThermoI.setTemp(25);
    ThermoI.performAction();
    std::cout << ThermoI.getDeviceType() << "\n";
    ThermoI.performAction();
}

void TestComponent4()
{
    std::cout << "\n🛠️  =================== Testing Component 4: Sensor Observations and Notifications =================== 🛠️\n";

    MotionSensor *sensor1 = new MotionSensor("MotionSensor");
    Temperature *sensor2 = new Temperature("TempSensor");

    Light *light1 = new Light("Light1", 80, 10);
    DoorLock *lck1 = new DoorLock("Lock1", 2, "grade 2");
    Alarm *alarm1 = new Alarm("Alarm1", 92, "grade 3");
    Thermostat *stat1 = new Thermostat("Thermostat1");

    Control control;

    std::cout << "\n🔍 \t ++++++++++++Details Before: ++++++++++++\n";
    std::cout << "Light status: " << light1->getStatus() << std::endl;
    std::cout << "Doorlock status: " << lck1->getStat() << std::endl;
    std::cout << "Alarm status: " << alarm1->getStatus() << std::endl;
    std::cout << "Thermostat status: " << stat1->getStatus() << std::endl;

    std::cout << "\n🌡️ \t ======WORKING WITH THE SENSORS:====== \n";
    sensor1->addDevice(light1);
    sensor1->addDevice(lck1);
    sensor1->addDevice(alarm1);
    sensor2->addDevice(stat1);

    sensor1->detectMotion();
    std::cout << "\n🔍 \t ++++++++++++Details After: ++++++++++++\n";
    std::cout << "Light status: " << light1->getStatus() << std::endl;
    std::cout << "Doorlock status: " << lck1->getStat() << std::endl;
    std::cout << "Alarm status: " << alarm1->getStatus() << std::endl;
    std::cout << "\n";

    stat1->setTemperature(25);
    sensor2->detectTemp();
    std::cout << "\n Thermostat status: " << stat1->getStatus() << std::endl;

    std::cout << "\n \t ======WORKING WITH THE Controller:====== \n";
    control.addDevice(light1);
    control.addDevice(lck1);
    control.addDevice(stat1);
    control.addDevice(alarm1);

    control.addSensor(sensor1);
    control.addSensor(sensor2);

    control.notifySpecificDevice(light1);
    control.notifySpecificDevice(lck1);
    stat1->setTemperature(25);
    control.notifySpecificDevice(stat1);
    control.notifySpecificDevice(alarm1);
}
