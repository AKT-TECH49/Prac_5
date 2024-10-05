// 
#include "SmartDevice.h"
#include "Room.h"
#include "HomeSection.h"

//
#include "Light.h"
#include "Thermostat.h"
#include "Alarm.h"
#include "DoorLock.h"

// 
#include "LightState.h"
#include "ThermoState.h"
#include "AlarmState.h"
#include "DoorLState.h"

//
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

// 
#include "TurnOffAllLights.h"
#include "LockAllDoors.h"
#include "MacroRoutine.h"
#include "DefuseAlarm.h"
#include "SwitchThermo.h"

#include <iostream>
#include <string>


void TestComponent1();
void TestComponent2();
void TestComponent3();
void TestComponent4();



int main()
{
    TestComponent1();
    TestComponent2();
    TestComponent3();
    TestComponent4();
    return 0;
}

void TestComponent1()
{
    std::cout << "~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~ COMPONENT 1 ~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_ \n";

    HomeSection *sec1 = new HomeSection("Ground_Floor");
    std::cout << "HomeSectionName is : " << sec1->getSectionName() << std::endl;
    //
    Room *livingRoom = new Room("LivingRoom");
    std::cout << "RoomName is : " << livingRoom->getRoomName() << std::endl;
    //
    Light *light1 = new Light("LedLight", 75, 10);
    DoorLock *doorL1 = new DoorLock("DoorLock", 2, "Grade2");
    Thermostat *thermo1 = new Thermostat("ThermoStat");
    Alarm *alarm1 = new Alarm("Alarm1", 90, "grade1");
    //
    //
    std::cout << "DeviceName is : " << light1->getDeviceType() << " with ID: " << light1->getId() << std::endl;
    std::cout << "DeviceName is : " << doorL1->getDeviceType() << " with ID: " << doorL1->getId() << std::endl;
    std::cout << "DeviceName is : " << thermo1->getDeviceType() << " with ID: " << thermo1->getId() << std::endl;
    std::cout << "DeviceName is : " << alarm1->getDeviceType() << " with ID: " << alarm1->getId() << std::endl;
    //
    livingRoom->addDevice(light1);
    livingRoom->addDevice(doorL1);
    livingRoom->addDevice(thermo1);
    livingRoom->addDevice(alarm1);

    std::cout << "Devices in the " << livingRoom->getRoomName() << " with ID: " << livingRoom->getId() << std::endl;
    std::cout << livingRoom->getDeviceType() << std::endl;

    ////
    std::cout << "LETS PLAY!!!!" << std::endl;

    std::cout << light1->getStatus() << std::endl;
    std::cout << doorL1->getStat() << std::endl;
    std::cout << thermo1->getStatus() << std::endl;
    std::cout << alarm1->getStatus() << std::endl;

    std::cout << "\t ======actions===== \n";
    light1->performAction();
    doorL1->performAction();
    thermo1->setTemperature(25);
    thermo1->performAction();
    alarm1->performAction();

    std::cout << light1->getStatus() << std::endl;
    std::cout << doorL1->getStat() << std::endl;
    std::cout << thermo1->getStatus() << std::endl;
    std::cout << alarm1->getStatus() << std::endl;


    //direct set of states

    //light
    std::cout << "\t ======MANUAL SET OF STATES===== \n";

    std::cout << "\t \t -*-*-*-*-*-*-*-* light *-*-*-*-*-*-*-*-*-* \n";
    OnState* on = new OnState();
    OffState* off = new OffState();

    std::cout<< "Created state is: " <<on->toString()<<std::endl;
    std::cout<< "Created state is: " <<off->toString()<<std::endl;

    light1->setState(on);
    std::cout << light1->getStatus() << std::endl;
    
    light1->setState(off);
    std::cout << light1->getStatus() << std::endl;
    //
    std::cout << "\t \t -*-*-*-*-*-*-*-* Alarm *-*-*-*-*-*-*-*-*-* \n";
    notActive* deactive = new notActive();
    Active* active = new Active();

    std::cout<< "Created state is: " <<active->toString()<<std::endl;
    std::cout<< "Created state is: " <<deactive->toString()<<std::endl;
    
    alarm1->setStatus(active);
    std::cout << alarm1->getStatus() << std::endl;
    alarm1->setStatus(deactive);
    std::cout << alarm1->getStatus() << std::endl;

    std::cout << "\t \t -*-*-*-*-*-*-*-* DoorLock *-*-*-*-*-*-*-*-*-* \n";
    UnlockedState* unlock = new UnlockedState();
    LockedState* lock = new LockedState();

    std::cout<< "Created state is: " <<unlock->toString()<<std::endl;
    std::cout<< "Created state is: " <<lock->toString()<<std::endl;

    doorL1->setStat(unlock);
    std::cout << doorL1->getStat() << std::endl;
    doorL1->setStat(lock);
    std::cout << doorL1->getStat() << std::endl;

    std::cout << "\t \t -*-*-*-*-*-*-*-* Thermostat *-*-*-*-*-*-*-*-*-* \n";
    IdleState* idle = new IdleState();
    MonitorState* monitor = new MonitorState();
    ColdState* cold = new ColdState();
    HotState* hot = new HotState();
    MildState* mild = new MildState();

    std::cout<< "Created state is: " <<idle->toString()<<std::endl;
    std::cout<< "Is it Cold? : " <<idle->isCold()<<std::endl;
    std::cout<< "Is it Hot? : " <<idle->isHot()<<std::endl;
    std::cout<< "Is it Mild? : "<<idle->isMild()<<std::endl;

    std::cout<< "Created state is: " <<monitor->toString()<<std::endl;
    std::cout<< "Is it Cold? : " <<monitor->isCold()<<std::endl;
    std::cout<< "Is it Hot? : " <<monitor->isHot()<<std::endl;
    std::cout<< "Is it Mild? : "<<monitor->isMild()<<std::endl;

    std::cout<< "Created state is: " <<cold->toString()<<std::endl;
    std::cout<< "Is it Cold? : " <<cold->isCold()<<std::endl;
    std::cout<< "Is it Hot? : " <<cold->isHot()<<std::endl;
    std::cout<< "Is it Mild? : "<<cold->isMild()<<std::endl;

    std::cout<< "Created state is: " <<hot->toString()<<std::endl;
    std::cout<< "Is it Cold? : " <<hot->isCold()<<std::endl;
    std::cout<< "Is it Hot? : " <<hot->isHot()<<std::endl;
    std::cout<< "Is it Mild? : "<<hot->isMild()<<std::endl;

    std::cout<< "Created state is: " <<mild->toString()<<std::endl;
    std::cout<< "Is it Cold? : " <<mild->isCold()<<std::endl;
    std::cout<< "Is it Hot? : " <<mild->isHot()<<std::endl;
    std::cout<< "Is it Mild? : "<<mild->isMild()<<std::endl;
 
    thermo1->setState(idle);
    std::cout << thermo1->getStatus() << std::endl;
    thermo1->setState(monitor);
    std::cout << thermo1->getStatus() << std::endl;
    thermo1->setState(cold);
    std::cout << thermo1->getStatus()<< std::endl;
    thermo1->setState(hot);
    std::cout << thermo1->getStatus() << std::endl;
    thermo1->setState(mild);
    std::cout << thermo1->getStatus() << std::endl;

    





    // connection
    sec1->addRoom(livingRoom);
    std::cout << "Devices in the " << sec1->getSectionName() << " with ID: " << sec1->getId() << std::endl;
    sec1->displayHomeSection();
    std::cout << sec1->getDeviceType() << std::endl;

    delete sec1;  
}

void TestComponent2()
{
    std::cout << "~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~COMPONENT 2~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_ \n";
    std::cout << "\t ======Legacy Thermostat===== \n";
    LegendThermo *oldThermo = new LegendThermo();
    SmartThermostatIntegrator *ThermoI = new SmartThermostatIntegrator(oldThermo, "ThermoStat");
    std::cout << "Current Temp: " << ThermoI->getTemP() << std::endl;
    ThermoI->setTemp(25);
    ThermoI->performAction();
    std::cout << ThermoI->getDeviceType() << std::endl;
    ThermoI->performAction();

    delete ThermoI;
    delete oldThermo;
}

void TestComponent3()
{
    std::cout << "~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~COMPONENT 3~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_ \n";

    //devices
    Light* livingRoomLight = new Light("Living Room Light", 100, 60); 
    DoorLock* frontDoor = new DoorLock("Front Door", 1, "High");
    Alarm* livingRoomAlarm = new Alarm("Living Room Alarm", 80, "High");
    //commands
    TurnOffAllLights* turnOffLightsCmd = new TurnOffAllLights(livingRoomLight);
    LockAllDoors* lockFrontDoor = new LockAllDoors(frontDoor);
    DefuseAlarm* defuseAlarmCmd = new DefuseAlarm(livingRoomAlarm);
    //routines
    MacroRoutine* goodnightRoutine = new MacroRoutine();
    MacroRoutine* goodnightRoutine2 = new MacroRoutine();
    MacroRoutine* goodMorningR3 = new MacroRoutine();


    //test
    std::cout<<"=========== Testing the Lights Command ============= \n";

    goodnightRoutine->addCommand(turnOffLightsCmd);

    std::cout << "\nExecuting Goodnight Routine for Light:\n";
    std::cout << "Initial state of the light: " << livingRoomLight->getStatus() << "\n";
    goodnightRoutine->execute();
    std::cout << "Final state of the light: " << livingRoomLight->getStatus() << "\n";
    //
    std::cout<<std::endl;
    //
    std::cout << "When light is on: \n";
    OnState* on = new OnState();
    livingRoomLight->setState(on);
    goodnightRoutine->execute();
    std::cout << "Final state of the light: " << livingRoomLight->getStatus()<<"\n";
    
    goodnightRoutine->removeCommand(turnOffLightsCmd);



    std::cout<<" =========== Testing the Door Lock Command ============= \n";
    goodnightRoutine2->addCommand(lockFrontDoor);
    //
    std::cout << "\n Executing Goodnight Routine for Doorlock:\n";
    goodnightRoutine2->execute();
    std::cout << "Final state of front door: " << frontDoor->getStat() << "\n";
    //
    std::cout << "When locked: \n";
    LockedState* locked = new LockedState();
    frontDoor->setStat(locked);
    
    std::cout << "Manual state: " << frontDoor->getStat() << "\n";
    goodnightRoutine2->execute();
    goodnightRoutine2->removeCommand(lockFrontDoor);




    std::cout<<" =========== Testing the Alarm Command ============= \n";
    goodMorningR3->addCommand(defuseAlarmCmd);

    std::cout << "\nExecuting Goodmorning Routine for Alarm:\n";
    goodMorningR3->execute();
    std::cout << "Final state of alarm: " <<livingRoomAlarm->getStatus() << "\n";
    //
    Active* activate =  new Active();
    livingRoomAlarm->setStatus(activate);
    std::cout << "\nManual state: " << livingRoomAlarm->getStatus() << "\n";
    goodMorningR3->execute();
    std::cout << "Final state of alarm: " << livingRoomAlarm->getStatus() <<std::endl;
    goodMorningR3->removeCommand(defuseAlarmCmd);

    
   
   //
   delete turnOffLightsCmd;
   delete lockFrontDoor;
   delete defuseAlarmCmd;

   delete goodnightRoutine;
   delete goodnightRoutine2;
   delete goodMorningR3;

   delete livingRoomLight;
   delete frontDoor;
   delete livingRoomAlarm;
}

void TestComponent4()
{
    std::cout << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/COMPONENT 4 /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/  \n";

    MotionSensor *sensor1 = new MotionSensor("MotionSensor");
    Temperature *sensor2 = new Temperature("TempSensor");

    Light *light1 = new Light("Light1", 80, 10);
    DoorLock *lck1 = new DoorLock("Lock1", 2, "grade 2");
    Alarm *alarm1 = new Alarm("Alarm1", 92, "grade 3");
    Thermostat *stat1 = new Thermostat("Thermostat1");

    Room *room1 = new Room("livingRoom");
    room1->addDevice(light1);
    room1->addDevice(lck1);
    room1->addDevice(alarm1);
    room1->addDevice(stat1);
    std::cout << "DETAILS: " << room1->displayRooms() << std::endl;

    HomeSection *ground = new HomeSection("GroundFloor");
    ground->addRoom(room1);
    ground->displayHomeSection();

    Control *control = new Control();

    std::cout << "\n \t ++++++++++++Details Before: ++++++++++++\n";
    std::cout << "Light status: " << light1->getStatus() << std::endl;
    std::cout << "Doorlock status: " << lck1->getStat() << std::endl;
    std::cout << "Alarm status: " << alarm1->getStatus() << std::endl;
    std::cout << "Thermostat status: " << stat1->getStatus() << std::endl;

    std::cout << "\n \t ======WORKING WITH THE SENSORS:====== \n";
    sensor1->addDevice(light1);
    sensor1->addDevice(lck1);
    sensor1->addDevice(alarm1);
    sensor2->addDevice(stat1);

    sensor1->detectMotion();
    std::cout << "\n \t ++++++++++++Details After: ++++++++++++\n";
    std::cout << "Light status: " << light1->getStatus() << std::endl;
    std::cout << "Doorlock status: " << lck1->getStat() << std::endl;
    std::cout << "Alarm status: " << alarm1->getStatus() << std::endl;
    std::cout << "\n";

    stat1->setTemperature(25);
    sensor2->detectTemp();
    std::cout << "\n Thermostat status: " << stat1->getStatus() << std::endl;

    std::cout << "\n \t ======WORKING WITH THE Controller:====== \n";
    control->addDevice(light1);
    control->addDevice(lck1);
    control->addDevice(stat1);
    control->addDevice(alarm1);

    control->addSensor(sensor1);
    control->addSensor(sensor2);

    control->notifySpecificDevice(light1);
    control->notifySpecificDevice(lck1);
    stat1->setTemperature(25);
    control->notifySpecificDevice(stat1);
    control->notifySpecificDevice(alarm1);

    // remove
    control->removeDevice(alarm1);
    control->removeDevice(stat1);
    control->removeDevice(lck1);
    control->removeDevice(light1);
    //
    control->removeSensor(sensor2);
    control->removeSensor(sensor1);
    //
    ground->removeRoom(room1);
    //
    room1->removeDevice(alarm1);
    room1->removeDevice(stat1);
    room1->removeDevice(lck1);
    room1->removeDevice(light1);

    delete control;
    delete ground;
    delete room1;
    //
    delete sensor1;
    delete sensor2;
    //
    delete alarm1;
    delete lck1;
    delete light1;
    delete stat1;
}