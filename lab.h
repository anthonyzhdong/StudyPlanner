#include <string>
#pragma once

using namespace std;

class Lab {
private:
    string eventType;
    string paperCode;
    int startTime;
    int endTime;
    string location;
    int day;
    int week;

public:
    // constructor
    Lab(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week);

    // getter methods
    string getEventType();
    string getPaperCode() ;
    int getStartTime() ;
    int getEndTime() ;
    string getLocation() ;
    int getDay() ;
    int getWeek() ;

    // setter methods
    void setEventType(string& eventType);
    void setPaperCode( string& paperCode);
    void setStartTime(int startTime);
    void setEndTime(int endTime);
    void setLocation( string& location);
    void setDay(int day);
    void setWeek(int week);

    // displays lab information
    void displayInfo() ;
};