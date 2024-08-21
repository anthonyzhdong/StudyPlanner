#include <string>
#pragma once

using namespace std;

class Tutorial {
private:
    string eventType;
    string paperCode;
    int startTime;
    int endTime;
    string location;
    int day;
    int week;

public:
    // ructor
    Tutorial(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week);

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

    // display tutorial information
    void displayInfo() ;
};