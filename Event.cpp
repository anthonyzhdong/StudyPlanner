#include "Event.h"

// Constructor Implementation
Event::Event(std::string eventName, int startTime, int endTime, int day, int week)
    : eventName(eventName), startTime(startTime), endTime(endTime), day(day), week(week) 
{
}

// Getter Implementations
std::string Event::getEventName() const
{
    return eventName;
}

int Event::getStartTime() const
{
    return startTime;
}

int Event::getEndTime() const
{
    return endTime;
}

int Event::getDay() const
{
    return day;
}

int Event::getWeek() const
{
    return week;
}
