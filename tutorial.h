#pragma once

#include <string>

class Tutorial {
private:
    std::string paperCode;
    int startTime;
    int endTime;
    std::string location;
    int day;
    int week;

public:
    // Constructor
    Tutorial(std::string paperCode, int startTime, int endTime, std::string location, int day, int week);

    // Getters
    std::string getPaperCode();
    int getStartTime();
    int getEndTime();
    std::string getLocation();
    int getDay();
    int getWeek();

    // Setters
    void setPaperCode(std::string paperCode);
    void setStartTime(int startTime);
    void setEndTime(int endTime);
    void setLocation(std::string location);
    void setDay(int day);
    void setWeek(int week);

    // Display
    void displayInfo();
};