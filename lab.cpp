#include <iostream>
#include "lab.h"

using namespace std;

// constructor
// class Lab : public eventSkeleton{

// }
Lab::Lab(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week)
    : eventSkeleton(paperCode, day, week), eventType(eventType), startTime(startTime), endTime(endTime), location(location){
}

// getter methods
string Lab::getEventType(){
    return eventType;
}

// string Lab::getPaperCode()  {
//     return paperCode;
// }

int Lab::getStartTime()  {
    return startTime;
}

int Lab::getEndTime()  {
    return endTime;
}

string Lab::getLocation()  {
    return location;
}

// int Lab::getDay()  {
//     return day;
// }

// int Lab::getWeek()  {
//     return week;
// }



// setter methods
void Lab:: setEventType(string& eventType) {
    this->eventType = eventType;
}

// void Lab::setPaperCode( string& paperCode) {
//     this->paperCode = paperCode;
// }

void Lab::setStartTime(int startTime) {
    this->startTime = startTime;
}

void Lab::setEndTime(int endTime) {
    this->endTime = endTime;
}

void Lab::setLocation( string& location) {
    this->location = location;
}

// void Lab::setDay(int day) {
//     this->day = day;
// }

// void Lab::setWeek(int week) {
//     this->week = week;
// }

// displays lab information
void Lab::displayInfo()  {
    cout << "Lab for " << getPaperCode() << " at " << location << " on day " << getDay() << " of week " << getWeek() << " from " << startTime << " to " << endTime << endl;
}