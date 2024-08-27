#pragma once

#include <vector>
#include "eventSkeleton.h"

// Forward declaration of classes
class Event;
class Day;
class Week;
class Calendar;

// Day class definition
class Day {
public:
    vector<eventSkeleton> events;
    int dayNumber;

public:
    Day(int dayNumber);
    bool addEvent(eventSkeleton& e);
    // Additional methods for Day class
};

// Week class definition
class Week {
public:
    std::vector<Day> days;
    int weekNumber;

public:
    Week(int weekNumber);
    bool addEvent(eventSkeleton& e);
    // Additional methods for Week class
};

// Calendar class definition
class Calendar {
private:
    std::vector<Week> weeks;

public:
    Calendar();
    void display();
    bool addEvent(eventSkeleton& e);
    bool removeEvent(eventSkeleton& e);
    bool editEvent(eventSkeleton& e);
    bool test();
    // Additional methods for Calendar class
};
