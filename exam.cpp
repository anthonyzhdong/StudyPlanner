#include <iostream>
#include "exam.h"

using namespace std;

// constructor
Exam::Exam(string eventType, string paperCode, int startTime, int endTime, string location, int day, int week)
    : eventSkeleton(paperCode, day, week), eventType(eventType), startTime(startTime), endTime(endTime), location(location)
{
}

// getter methods
string Exam::getEventType()
{
    return eventType;
}

int Exam::getStartTime()
{
    return startTime;
}

int Exam::getEndTime()
{
    return endTime;
}

string Exam::getLocation()
{
    return location;
}

// setter methods

void Exam::setEventType(string &eventType)
{
    this->eventType = eventType;
}

void Exam::setStartTime(int startTime)
{
    this->startTime = startTime;
}

void Exam::setEndTime(int endTime)
{
    this->endTime = endTime;
}

void Exam::setLocation(string &location)
{
    this->location = location;
}

// displays exam information
void Exam::displayInfo()
{
    cout << "Exam for " << getPaperCode() << " at " << location << " on day " << getDay() << " of week " << getWeek() << " from " << startTime << " to " << endTime << endl;
}