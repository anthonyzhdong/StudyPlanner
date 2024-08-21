#include <iostream>
#include "lecture.h"
#include "eventSkeleton.h"
using namespace std;

// constructor
// Lecture::Lecture(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week)
//     : eventType(eventType), paperCode(paperCode), startTime(startTime), endTime(endTime), location(location), day(day), week(week) {
// }
Lecture::Lecture(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week)
    : eventSkeleton(paperCode, day, week), eventType(eventType), startTime(startTime), endTime(endTime), location(location) {
}

// getter methods

string Lecture::getEventType(){
    return eventType;
}
// string Lecture::getPaperCode() {
//     return paperCode;
// }

int Lecture::getStartTime()  {
    return startTime;
}

int Lecture::getEndTime()  {
    return endTime;
}

string Lecture::getLocation()  {
    return location;
}

// int Lecture::getDay()  {
//     return day;
// }

// int Lecture::getWeek()  {
//     return week;
// }

// setter methods
void Lecture:: setEventType(string& eventType) {
    this->eventType = eventType;
}
// void Lecture::setPaperCode( string& paperCode) {
//     this->paperCode = paperCode;
// }

void Lecture::setStartTime(int startTime) {
    this->startTime = startTime;
}

void Lecture::setEndTime(int endTime) {
    this->endTime = endTime;
}

void Lecture::setLocation( string& location) {
    this->location = location;
}

// void Lecture::setDay(int day) {
//     this->day = day;
// }

// void Lecture::setWeek(int week) {
//     this->week = week;
// }

// displays lecture information
void Lecture::displayInfo()  {
    cout << "Lecture for " << getPaperCode() << " at " << location << " on day " << getDay() << " of week " << getWeek() << " from " << startTime << " to " << endTime << endl;
}