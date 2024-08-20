#include <string>
#pragma once

using namespace std;

class Lab {
private:
    string paperCode;
    int startTime;
    int endTime;
    string location;
    int day;
    int week;

public:
    // constructor
    Lab(string paperCode, int startTime, int endTime, string location, int day, int week);

    // getter methods
    string getPaperCode() const;
    int getStartTime() const;
    int getEndTime() const;
    string getLocation() const;
    int getDay() const;
    int getWeek() const;

    // setter methods
    void setPaperCode(const string& paperCode);
    void setStartTime(int startTime);
    void setEndTime(int endTime);
    void setLocation(const string& location);
    void setDay(int day);
    void setWeek(int week);

    // displays lab information
    void displayInfo() const;
};