#include <iostream>
#include <string>
#include "lecture.h"

class lecture{
private:
    std::string paperCode;
    int startTime;
    int endTime;
    std::string location;
    int day;
    int week;

public:
    // constructor
    lecture(std::string paperCode, int startTime, int endTime, std::string location, int day, int week){
        this->paperCode = paperCode;
        this->startTime = startTime;
        this->endTime = endTime;
        this->location = location;
        this->day = day;
        this->week = week;
    }

    // getters
    std::string getPaperCode(){
        return paperCode;
    }
    int getStartTime(){
        return startTime;
    }
    int getEndTime(){
        return endTime;
    }
    std::string getLocation(){
        return location;
    }
    int getDay(){
        return day;
    }
    int getWeek(){
        return week;
    }

    // setters
    void setPaperCode(std::string paperCode){
        this->paperCode = paperCode;
    }
    void setStartTime(int startTime){
        this->startTime = startTime;
    }
    void setEndTime(int endTime){
        this->endTime = endTime;
    }
    void setLocation(std::string location){
        this->location = location;
    }
    void setDay(int day){
        this->day = day;
    }
    void setWeek(int week){
        this->week = week;
    }

    // display
    void displayInfo(){
        std::cout << "Lecture for " << paperCode << " at " << location << " on day " << day << " at " << startTime << " to " << endTime << std::endl;
    }
}