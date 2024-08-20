#include "tutorial.h"
#include <iostream>

class tutorial{

private:
    std::string paperCode;
    int startTime;
    int endTime;
    std::string location;
    int day;
    int week;
    
public:
    // Constructor
    tutorial::tutorial(std::string paperCode, int startTime, int endTime, std::string location, int day, int week) {
        this->paperCode = paperCode;
        this->startTime = startTime;
        this->endTime = endTime;
        this->location = location;
        this->day = day;
        this->week = week;
    }

    // Getters
    std::string tutorial::getPaperCode() {
        return paperCode;
    }

    int tutorial::getStartTime() {
        return startTime;
    }

    int tutorial::getEndTime() {
        return endTime;
    }

    std::string tutorial::getLocation() {
        return location;
    }

    int tutorial::getDay() {
        return day;
    }

    int tutorial::getWeek() {
        return week;
    }

    // Setters
    void tutorial::setPaperCode(std::string paperCode) {
        this->paperCode = paperCode;
    }

    void tutorial::setStartTime(int startTime) {
        this->startTime = startTime;
    }

    void tutorial::setEndTime(int endTime) {
        this->endTime = endTime;
    }

    void tutorial::setLocation(std::string location) {
        this->location = location;
    }

    void tutorial::setDay(int day) {
        this->day = day;
    }

    void tutorial::setWeek(int week) {
        this->week = week;
    }

    // Display
    void tutorial::displayInfo() {
        std::cout << "tutorial for " << paperCode << " at " << location << " on day " << day << " at " << startTime << " to " << endTime << std::endl;
    }
}