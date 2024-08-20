#include <iostream>
#include "tutorial.h"

using namespace std;

// constructor
Tutorial::Tutorial(string paperCode, int startTime, int endTime, string location, int day, int week)
    : paperCode(paperCode), startTime(startTime), endTime(endTime), location(location), day(day), week(week) {
}

// getter methods
string Tutorial::getPaperCode() const {
    return paperCode;
}

int Tutorial::getStartTime() const {
    return startTime;
}

int Tutorial::getEndTime() const {
    return endTime;
}

string Tutorial::getLocation() const {
    return location;
}

int Tutorial::getDay() const {
    return day;
}

int Tutorial::getWeek() const {
    return week;
}

// setter methods
void Tutorial::setPaperCode(const string& paperCode) {
    this->paperCode = paperCode;
}

void Tutorial::setStartTime(int startTime) {
    this->startTime = startTime;
}

void Tutorial::setEndTime(int endTime) {
    this->endTime = endTime;
}

void Tutorial::setLocation(const string& location) {
    this->location = location;
}

void Tutorial::setDay(int day) {
    this->day = day;
}

void Tutorial::setWeek(int week) {
    this->week = week;
}

// display tutorial information
void Tutorial::displayInfo() const {
    cout << "Tutorial for " << paperCode << " at " << location << " on day " << day << " of week " << week << " from " << startTime << " to " << endTime << endl;
}
