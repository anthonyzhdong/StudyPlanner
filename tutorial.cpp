#include <iostream>
#include "tutorial.h"

using namespace std;

// constructor
// Tutorial::Tutorial(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week)
//     : eventType(eventType), paperCode(paperCode), startTime(startTime), endTime(endTime), location(location), day(day), week(week) {
// }
Tutorial::Tutorial(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week)
    : eventSkeleton(paperCode, day, week),eventType(eventType), startTime(startTime), endTime(endTime), location(location) {
}

// getter methods
string Tutorial::getEventType() {
    return eventType;
}
// string Tutorial::getPaperCode()  {
//     return paperCode;
// }

int Tutorial::getStartTime()  {
    return startTime;
}

int Tutorial::getEndTime()  {
    return endTime;
}

string Tutorial::getLocation()  {
    return location;
}

// int Tutorial::getDay()  {
//     return day;
// }

// int Tutorial::getWeek()  {
//     return week;
// }

// setter methods
void Tutorial::setEventType(string& eventType) {
    this->eventType = eventType;
}
// void Tutorial::setPaperCode( string& paperCode) {
//     this->paperCode = paperCode;
// }

void Tutorial::setStartTime(int startTime) {
    this->startTime = startTime;
}

void Tutorial::setEndTime(int endTime) {
    this->endTime = endTime;
}

void Tutorial::setLocation( string& location) {
    this->location = location;
}

// void Tutorial::setDay(int day) {
//     this->day = day;
// }

// void Tutorial::setWeek(int week) {
//     this->week = week;
// }

// display tutorial information
void Tutorial::displayInfo()  {
    cout << "Tutorial for " << getPaperCode() << " at " << location << " on day " << getDay() << " of week " << getWeek() << " from " << startTime << " to " << endTime << endl;
}
