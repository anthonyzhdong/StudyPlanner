#include <string>
#include "eventSkeleton.h"
#pragma once

using namespace std;

class Assignment : public eventSkeleton
{
private:
    string eventType;
    string assignmentName;
    int dueTime;

public:
    // constructor
    Assignment(string paperCode, string assignmentName, int dueTime, int day, int week);

    // getter methods
    string getEventType();
    string getAssignmentName();
    int getDueTime();

    // setter methods
    void setEventType(string &eventType);
    void setAssignmentName(string &assignmentName);
    void setDueTime(int dueTime);
    void setDueDate(int dueDate);

    // displays assignment information
    void displayInfo();
};