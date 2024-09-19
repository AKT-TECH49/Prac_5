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





#include <iostream>
#include <string>

void TestComponent1();

int main()
{
    TestComponent1();

    return 0;
}

void TestComponent1()
{
    HomeSection* sec1 =new  HomeSection("Ground_Floor");
    std::cout<<"HomeSectionName is : "<< sec1->getSectionName()<<std::endl;

    Room* livingRoom = new Room("LivingRoom");
    std::cout<<"RoomName is : "<< livingRoom->getRoomName()<<std::endl;

    Light* light1 = new Light("LedLight" , 75 , 10);
    DoorLock* doorL1 = new DoorLock("DoorLock" , 2 , "Grade2");
    Thermostat* thermo1 = new Thermostat("ThermoStat" , 12);
    Alarm* alarm1 = new Alarm("Alarm1" , 90 , "grade1");
    std::cout<<"DeviceName is : "<< light1->getDeviceType()<<std::endl;
    std::cout<<"DeviceName is : "<< doorL1->getDeviceType()<<std::endl;
    std::cout<<"DeviceName is : "<< thermo1->getDeviceType()<<std::endl;
    std::cout<<"DeviceName is : "<< alarm1->getDeviceType()<<std::endl;

    livingRoom->addDevice(light1);
    livingRoom->addDevice(doorL1);
    livingRoom->addDevice(thermo1);
    livingRoom->addDevice(alarm1);
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