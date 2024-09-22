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
#include "SwitchThermo.h"

#include <iostream>
#include <string>

// Test for component 1:
void TestComponent1();

// Test for component 2:
void TestComponent2();
=======
void TestComponent3();
void TestComponent4();



int main()
{
    // TestComponent1();

    TestComponent2();

    // TestComponent3();
    TestComponent4();


    return 0;
}

void TestComponent1()
{
    HomeSection *sec1 = new HomeSection("Ground_Floor");
    std::cout << "HomeSectionName is : " << sec1->getSectionName() << std::endl;

    Room *livingRoom = new Room("LivingRoom");
    std::cout << "RoomName is : " << livingRoom->getRoomName() << std::endl;


    Light *light1 = new Light("LedLight", 75, 10);
    DoorLock *doorL1 = new DoorLock("DoorLock", 2, "Grade2");
    Thermostat *thermo1 = new Thermostat("ThermoStat", 12);
    Alarm *alarm1 = new Alarm("Alarm1", 90, "grade1");
    std::cout << "DeviceName is : " << light1->getDeviceType() << std::endl;
    std::cout << "DeviceName is : " << doorL1->getDeviceType() << std::endl;
    std::cout << "DeviceName is : " << thermo1->getDeviceType() << std::endl;
    std::cout << "DeviceName is : " << alarm1->getDeviceType() << std::endl;




    livingRoom->addDevice(light1);
    livingRoom->addDevice(doorL1);
    livingRoom->addDevice(thermo1);
    livingRoom->addDevice(alarm1);

    std::cout << "Devices in the LivingRoom: " << std::endl;
    std::cout << livingRoom->getDeviceType() << std::endl;

    std::cout << "LETS PLAY!!!!" << std::endl;
    // default states
    std::cout << light1->getStatus() << std::endl;
    std::cout << doorL1->getStat() << std::endl;
    std::cout << thermo1->getStatus() << std::endl;
    std::cout << alarm1->getStatus() << std::endl;
    // actions
    std::cout << "\t ======actions===== \n";
    light1->performAction();
    doorL1->performAction();
    thermo1->performAction();
    alarm1->performAction();
    // updated
    std::cout << light1->getStatus() << std::endl;
    std::cout << doorL1->getStat() << std::endl;
    std::cout << thermo1->getStatus() << std::endl;
    std::cout << alarm1->getStatus() << std::endl;
    // connection
    sec1->addRoom(livingRoom);
    sec1->displayHomeSection();
    std::cout << sec1->getDeviceType() << std::endl;
}

void TestComponent2()
{
    // =========== Testing the Lights Command =============
    Light *livingRoomLight = new Light("Living Room Light", 100, 60); // Brightness = 100, Power = 60W
    std::cout << "Initial state of the light: " << livingRoomLight->getStatus() << "\n";

    // Create the TurnOffAllLights command
    TurnOffAllLights *turnOffLightsCmd = new TurnOffAllLights(livingRoomLight);

    // Create a macro routine
    MacroRoutine goodnightRoutine;
    goodnightRoutine.addCommand(turnOffLightsCmd);

    // Execute the macro routine
    std::cout << "\nExecuting Goodnight Routine:\n";
    goodnightRoutine.execute();

    // Check the final state of the light
    std::cout << "\nFinal state of the light: " << livingRoomLight->getStatus() << "\n";

    // =========== Testing the Door Lock Command =============
    DoorLock *frontDoor = new DoorLock("Front Door", 1, "High");
    DoorLock *backDoor = new DoorLock("Back Door", 1, "Medium");

    // Create specific commands to lock each door
    SmartDeviceCommand *lockFrontDoor = new LockAllDoors(frontDoor);
    SmartDeviceCommand *lockBackDoor = new LockAllDoors(backDoor);

    // Create a MacroRoutine for the Goodnight routine
    MacroRoutine goodnightRoutine2;

    // Add the commands to lock all doors
    goodnightRoutine2.addCommand(lockFrontDoor);
    goodnightRoutine2.addCommand(lockBackDoor);

    // Execute the Goodnight routine
    std::cout << "Executing Goodnight Routine:\n";
    goodnightRoutine2.execute();

    // Check the final state of the doors
    std::cout << "Final state of front door: " << frontDoor->getStat() << "\n";
    std::cout << "Final state of back door: " << backDoor->getStat() << "\n";

    // Re-executing the routine
    std::cout << "\n-- Test 2: Re-executing Goodnight Routine --\n";
    goodnightRoutine2.execute();

    // =========== Testing the Defuse Alarm Command =============
    Alarm *livingRoomAlarm = new Alarm("Living Room Alarm", 80, "High");
    DefuseAlarm *defuseLivingRoomAlarm = new DefuseAlarm(livingRoomAlarm);

    // Create a macro routine and add commands
    MacroRoutine goodnightRoutine3;
    goodnightRoutine3.addCommand(defuseLivingRoomAlarm);

    // Execute the Goodnight Routine
    std::cout << "Executing Goodnight Routine:\n";
    goodnightRoutine3.execute();

    // =========== Testing the Switch Thermostat Command =============
    Thermostat *livingRoomThermo = new Thermostat("Living Room Thermostat", 20); // Initial temp of 20°C

    SmartDeviceCommand *switchToHot = new SwitchThermo(livingRoomThermo, 28);  // Setting to 28°C
    SmartDeviceCommand *switchToCold = new SwitchThermo(livingRoomThermo, 15); // Setting to 15°C

    MacroRoutine goodMorningRoutine4;
    goodMorningRoutine4.addCommand(switchToHot); // Switch thermostat to hot
    goodMorningRoutine4.execute();               // Executes all added commands

    switchToCold->execute(); // Direct test without MacroRoutine
}

    std::cout<<"Devices in the LivingRoom: "<<std::endl;
   std::cout<< livingRoom->getDeviceType() <<std::endl;

   std::cout<<"LETS PLAY!!!!"<<std::endl;
   //default states
   std::cout<<light1->getStatus()<<std::endl;
   std::cout<<doorL1->getStat()<<std::endl;
   std::cout<<thermo1->getStatus()<<std::endl;
   std::cout<<alarm1->getStatus() <<std::endl;
   //actions
   std::cout<<"\t ======actions===== \n";
   light1->performAction();
   doorL1->performAction();
   thermo1->setTemperature(25);
   thermo1->performAction();
   alarm1->performAction();
   //updated
   std::cout<<light1->getStatus()<<std::endl;
   std::cout<<doorL1->getStat()<<std::endl;
   std::cout<<thermo1->getStatus()<<std::endl;
   std::cout<<alarm1->getStatus() <<std::endl;
   //connection
   sec1->addRoom(livingRoom);
   sec1->displayHomeSection();
   std::cout<<sec1->getDeviceType()<<std::endl;


}


void TestComponent3()
{
std::cout<<"~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~COMPONENT 2~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_ \n";
    std::cout<<"\t ======Legacy Thermostat===== \n";
    LegendThermo oldThermo;
    SmartThermostatIntegrator ThermoI(&oldThermo , "ThermoStat");
    std::cout<<"Current Temp: "<<ThermoI.getTemP()<<std::endl;
    ThermoI.setTemp(25);
    ThermoI.performAction();
    std::cout<< ThermoI.getDeviceType() <<std::endl;
    ThermoI.performAction();

}


void TestComponent4()
{
    std::cout<<"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/COMPONENT 4 /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/  \n";
   
    MotionSensor* sensor1 = new MotionSensor("MotionSensor");
    Temperature* sensor2 = new Temperature("TempSensor");

    Light* light1 = new Light("Light1" ,80 ,10 );
    DoorLock* lck1 = new DoorLock("Lock1" , 2 ,"grade 2");
    Alarm* alarm1 = new Alarm("Alarm1" ,92,"grade 3");
    Thermostat * stat1 = new Thermostat("Thermostat1" );

    Control control;


     std::cout<<"\n \t ++++++++++++Details Before: ++++++++++++\n";
      std::cout<<"Light status: "<<light1->getStatus()<<std::endl;
      std::cout<<"Doorlock status: "<<lck1->getStat()<<std::endl;
      std::cout<<"Alarm status: "<<alarm1->getStatus()<<std::endl;
      std::cout<<"Thermostat status: "<<stat1->getStatus()<<std::endl;



     std::cout<<"\n \t ======WORKING WITH THE SENSORS:====== \n";
     sensor1->addDevice(light1);
     sensor1->addDevice(lck1);
     sensor1->addDevice(alarm1);
     sensor2->addDevice(stat1);

     sensor1->detectMotion();
      std::cout<<"\n \t ++++++++++++Details After: ++++++++++++\n";
      std::cout<<"Light status: "<<light1->getStatus()<<std::endl;
      std::cout<<"Doorlock status: "<<lck1->getStat()<<std::endl;
      std::cout<<"Alarm status: "<<alarm1->getStatus()<<std::endl;
      std::cout<<"\n";

     stat1->setTemperature(25);
     sensor2->detectTemp();
     std::cout<<"\n Thermostat status: "<<stat1->getStatus()<<std::endl;

    std::cout<<"\n \t ======WORKING WITH THE Controller:====== \n";
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
