#include "eventSkeleton.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

// constructor
eventSkeleton::eventSkeleton(EventType eventType, string paperCode, int day, int week, int startTime, int endTime, string location)
    : paperCode(paperCode), location(location), day(day), week(week), startTime(startTime), endTime(endTime), eventType(eventType)
{
}

// getter methods
EventType eventSkeleton::getEventType()
{
    return eventType;
}

string eventSkeleton::getEventTypeString(EventType type)
{
    switch (type)
    {
    case EventType::LECTURE:
        return "Lecture";
    case EventType::TUTORIAL:
        return "Tutorial";
    case EventType::LAB:
        return "Lab";
    case EventType::ASSIGNMENT:
        return "Assignment";
    case EventType::EXAM:
        return "Exam";
    case EventType::STUDY_SESSION:
        return "Study Session";
    default:
        return "Unknown";
    }
}
string eventSkeleton::getPaperCode() const
{
    return paperCode;
}
int eventSkeleton::getDay() const
{
    return day;
}

int eventSkeleton::getWeek() const
{
    return week;
}
int eventSkeleton::getStartTime() const
{
    return startTime;
}
int eventSkeleton::getEndTime() const
{
    return endTime;
}
string eventSkeleton::getLocation() const
{
    return location;
}

// setter methods
void eventSkeleton::setEventType(EventType eventType)
{
    this->eventType = eventType;
}
void eventSkeleton::setPaperCode(string &paperCode)
{
    this->paperCode = paperCode;
}
void eventSkeleton::setDay(int day)
{
    this->day = day;
}
void eventSkeleton::setWeek(int week)
{
    this->week = week;
}
void eventSkeleton::setStartTime(int startTime)
{
    this->startTime = startTime;
}
void eventSkeleton::setEndTime(int endTime)
{
    this->endTime = endTime;
}
void eventSkeleton::setLocation(string &location)
{
    this->location = location;
}

void eventSkeleton::displayInfo()
{
    cout << "Paper Code: " << getPaperCode() << "\nEvent Type: " << getEventTypeString(getEventType()) << "\nDay: " << getDay() << "\nWeek: " << getWeek() << "\nStart Time: " << getStartTime() << "\nEnd Time: " << getEndTime() << "\nLocation: " << getLocation() << endl;
}

void eventSkeleton::serialize(std::ofstream &outputFile) const
{
    outputFile << static_cast<int>(eventType) << std::endl;

    // Serialize other members
    outputFile << paperCode << std::endl;
    outputFile << day << std::endl;
    outputFile << week << std::endl;
    outputFile << startTime << std::endl;
    outputFile << endTime << std::endl;
    outputFile << location << std::endl;
}

bool eventSkeleton::test()
{
    bool passed = true;
    eventSkeleton testEvent = eventSkeleton(EventType::LECTURE, "COSC345", 1, 1, 930, 1000, "Mellor 3.1");
    // set up testEvent
    // change values
    testEvent.setEventType(EventType::TUTORIAL);
    string newCode = "COSC326";
    testEvent.setPaperCode(newCode);
    testEvent.setDay(2);
    testEvent.setWeek(2);
    testEvent.setStartTime(1400);
    testEvent.setEndTime(1500);
    string newLocation = "Mellor 3.2";
    testEvent.setLocation(newLocation);

    // test that values are set correctly
    if (testEvent.getEventType() != EventType::TUTORIAL)
    {
        cout << "Error: EventType not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getPaperCode() != newCode)
    {
        cout << "Error: Paper code not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getDay() != 2)
    {
        cout << "Error: Day not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getWeek() != 2)
    {
        cout << "Error: Week not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getStartTime() != 1400)
    {
        cout << "Error: Start time not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getEndTime() != 1500)
    {
        cout << "Error: End time not set correctly." << endl;
        passed = false;
    }
    if (testEvent.getLocation() != newLocation)
    {
        cout << "Error: Location not set correctly." << endl;
        passed = false;
    }

    if (testEvent.getEventTypeString(testEvent.getEventType()) != "Tutorial")
    {
        cout << "Error: getEventTypeString() not working." << endl;
        passed = false;
    }
    testEvent.displayInfo();
    if (passed)
    {
        cout << "EventSkeleton Test Passed" << endl;
    }
    else
    {
        cout << "EventSkeleton Test Failed" << endl;
    }

    return passed;
}