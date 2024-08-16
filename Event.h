#pragma once

#include <string>

class Event
{
public:
    // Constructor
    Event(std::string eventName, int startTime, int endTime, int day, int week);

    // Getters
    std::string getEventName() const;
    int getStartTime() const;
    int getEndTime() const;
    int getDay() const;
    int getWeek() const;

private:
    std::string eventName;
    int startTime;
    int endTime;
    int day;
    int week;
};