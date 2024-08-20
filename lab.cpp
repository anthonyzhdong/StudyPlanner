#include "lab.h"
#include <iostream>

// Constructor
lab::lab(std::string paperCode, int startTime, int endTime, std::string location, int day, int week) {
    this->paperCode = paperCode;
    this->startTime = startTime;
    this->endTime = endTime;
    this->location = location;
    this->day = day;
    this->week = week;
}

// Getters
std::string lab::getPaperCode() {
    return paperCode;
}

int lab::getStartTime() {
    return startTime;
}

int lab::getEndTime() {
    return endTime;
}

std::string lab::getLocation() {
    return location;
}

int lab::getDay() {
    return day;
}

int lab::getWeek() {
    return week;
}

// Setters
void lab::setPaperCode(std::string paperCode) {
    this->paperCode = paperCode;
}

void lab::setStartTime(int startTime) {
    this->startTime = startTime;
}

void lab::setEndTime(int endTime) {
    this->endTime = endTime;
}

void lab::setLocation(std::string location) {
    this->location = location;
}

void lab::setDay(int day) {
    this->day = day;
}

void lab::setWeek(int week) {
    this->week = week;
}

// Display
void lab::displayInfo() {
    std::cout << "lab for " << paperCode << " at " << location << " on day " << day << " at " << startTime << " to " << endTime << std::endl;
}