#include <iostream>
#include "assignment.h"

using namespace std;

// constructor
Assignment::Assignment(string paperCode, string assignmentName, int dueTime, int day, int week)
    : eventSkeleton(paperCode, day, week), eventType(eventType), assignmentName(assignmentName), dueTime(dueTime)
{
}

// getter methods
string Assignment::getEventType()
{
    return eventType;
}

string Assignment::getAssignmentName()
{
    return assignmentName;
}

int Assignment::getDueTime()
{
    return dueTime;
}

// setter methods

void Assignment::setEventType(string &eventType)
{
    this->eventType = eventType;
}

void Assignment::setAssignmentName(string &assignmentName)
{
    this->assignmentName = assignmentName;
}

void Assignment::setDueTime(int dueTime)
{
    this->dueTime = dueTime;
}

// displays assignment information
void Assignment::displayInfo()
{
    cout << "Assignment for " << getPaperCode() << " Due on " << getDay() << " of week " << getWeek() << " at " << dueTime << endl;
}