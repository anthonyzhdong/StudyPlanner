#include <iostream>
#include "lecture.h"

using namespace std;

// constructor
Lecture::Lecture(string paperCode, int startTime, int endTime, string location, int day, int week)
    : paperCode(paperCode), startTime(startTime), endTime(endTime), location(location), day(day), week(week) {
}

// getter methods
string Lecture::getPaperCode() const {
    return paperCode;
}

int Lecture::getStartTime() const {
    return startTime;
}

int Lecture::getEndTime() const {
    return endTime;
}

string Lecture::getLocation() const {
    return location;
}

int Lecture::getDay() const {
    return day;
}

int Lecture::getWeek() const {
    return week;
}

// setter methods
void Lecture::setPaperCode(const string& paperCode) {
    this->paperCode = paperCode;
}

void Lecture::setStartTime(int startTime) {
    this->startTime = startTime;
}

void Lecture::setEndTime(int endTime) {
    this->endTime = endTime;
}

void Lecture::setLocation(const string& location) {
    this->location = location;
}

void Lecture::setDay(int day) {
    this->day = day;
}

void Lecture::setWeek(int week) {
    this->week = week;
}

// displays lecture information
void Lecture::displayInfo() const {
    cout << "Lecture for " << paperCode << " at " << location << " on day " << day << " of week " << week << " from " << startTime << " to " << endTime << endl;
}