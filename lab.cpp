#include <iostream>
#include "lab.h"

using namespace std;

// constructor
Lab::Lab(string paperCode, int startTime, int endTime, string location, int day, int week)
    : paperCode(paperCode), startTime(startTime), endTime(endTime), location(location), day(day), week(week) {
}

// getter methods
string Lab::getPaperCode() const {
    return paperCode;
}

int Lab::getStartTime() const {
    return startTime;
}

int Lab::getEndTime() const {
    return endTime;
}

std::string Lab::getLocation() const {
    return location;
}

int Lab::getDay() const {
    return day;
}

int Lab::getWeek() const {
    return week;
}

// setter methods
void Lab::setPaperCode(const string& paperCode) {
    this->paperCode = paperCode;
}

void Lab::setStartTime(int startTime) {
    this->startTime = startTime;
}

void Lab::setEndTime(int endTime) {
    this->endTime = endTime;
}

void Lab::setLocation(const string& location) {
    this->location = location;
}

void Lab::setDay(int day) {
    this->day = day;
}

void Lab::setWeek(int week) {
    this->week = week;
}

// displays lab information
void Lab::displayInfo() const {
    cout << "Lab for " << paperCode << " at " << location << " on day " << day << " of week " << week << " from " << startTime << " to " << endTime << endl;
}