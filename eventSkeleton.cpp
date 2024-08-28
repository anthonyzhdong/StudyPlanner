#include "eventSkeleton.h"
#include <string>
#include <iostream>
using namespace std;

// constructor
eventSkeleton::eventSkeleton(EventType eventType, string paperCode, int day, int week, int startTime, int endTime, string location)
    : paperCode(paperCode), location(location),day(day), week(week), startTime(startTime), endTime(endTime), eventType(eventType){
}

// getter methods
EventType eventSkeleton::getEventType(){
    return eventType;
}
string eventSkeleton::getPaperCode(){
    return paperCode;
}
int eventSkeleton::getDay()
{
    return day;
}

int eventSkeleton::getWeek()
{
    return week;
}
int eventSkeleton::getStartTime(){
    return startTime;
}
int eventSkeleton::getEndTime(){
    return endTime;
}
string eventSkeleton::getLocation(){
    return location;
}


// setter methods
void eventSkeleton::setEventType(EventType eventType){
    this->eventType = eventType;
}
void eventSkeleton::setPaperCode(string& paperCode){
    this->paperCode = paperCode;
}
void eventSkeleton::setDay(int day)
{
    this->day = day;
}
void eventSkeleton::setWeek(int week)
{
    this->week = week;
}
void eventSkeleton::setStartTime(int startTime){
    this->startTime = startTime;
}
void eventSkeleton::setEndTime(int endTime){
    this->endTime = endTime;
}
void eventSkeleton::setLocation(string& location){
    this->location = location;
}

void eventSkeleton::displayInfo(){
    cout << static_cast<int>(getEventType()) << " for " << getPaperCode() << " at " << getLocation() 
              << " on day " << getDay() << " of week " << getWeek() 
              << " from " << getStartTime() << " to " << getEndTime() << endl;
}

bool test(eventSkeleton testEvent){
    bool passed = true;

    // set up testEvent
    // change values
    testEvent.setEventType(EventType::TUTORIAL);
    string newCode = "COSC326";
    testEvent.setPaperCode(newCode);
    testEvent.setDay(2);
    testEvent.setWeek(2);
    testEvent.setStartTime(1400);
    testEvent.setEndTime(1500);
    string newLocation = "Mellor 3.2";
    testEvent.setLocation(newLocation);

    // test that values are set correctly
    if (testEvent.getEventType() != EventType::TUTORIAL){
        cout << "Error: EventType not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getPaperCode() != newCode){
        cout << "Error: Paper code not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getDay() != 2){
        cout << "Error: Day not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getWeek() != 2){
        cout << "Error: Week not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getStartTime() != 1400){
        cout << "Error: Start time not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getEndTime() != 1500){
        cout << "Error: End time not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getLocation() != newLocation){
        cout << "Error: Location not set correctly." << endl;
        passed = false;
    }
    if(passed){
        cout << "EventSkeleton Test Passed" << endl;
    }else{
        cout << "EventSkeleton Test Failed" << endl;
    }

    return passed;

}
