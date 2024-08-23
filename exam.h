#include <string>
#include "eventSkeleton.h"
#pragma once

using namespace std;

class Exam : public eventSkeleton
{
private:
    string eventType;
    int startTime;
    int endTime;
    string location;

public:
    // constructor
    Exam(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week);

    // getter methods
    string getEventType();
    int getStartTime();
    int getEndTime();
    string getLocation();

    // setter methods
    void setEventType(string &eventType);
    void setStartTime(int startTime);
    void setEndTime(int endTime);
    void setLocation(string &location);

    // displays exam information
    void displayInfo();
};