#pragma once

#include <vector>
#include "eventSkeleton.h"
#include "assignment.h"
#include "exam.h"

// Forward declaration of classes
class Day;
class Week;
class Calendar;

/**
 * @class Day
 * @brief Represents a single day in a calendar, containing events, assignments, and exams.
 */
class Day {
public:
    vector<eventSkeleton> events;
    vector<Assignment> assignments;
    vector<Exam> exams;
    int dayNumber;

public:
    Day(int dayNumber);
    bool addEvent(eventSkeleton& e);
    // Additional methods for Day class
private:
    bool addEventToCalendar(eventSkeleton& d);
};

 

/**
 * @class Week
 * @brief Represents a week in a calendar, containing multiple days.
 */
class Week {
public:
    std::vector<Day> days;
    int weekNumber;

public:
    Week(int weekNumber);
    bool addEvent(eventSkeleton& e);
    // Additional methods for Week class
};

/**
 * @class Calendar
 * @brief Represents a calendar, containing multiple weeks.
 */
class Calendar {
private:
    std::vector<Week> weeks;

public:
    Calendar();
    void display();
    bool addEvent(eventSkeleton& e);
    bool removeEvent(eventSkeleton& e);
    bool editEvent(eventSkeleton& e);
    void displayWeek(int week);
    void displaySemester(int semester);
    bool test();
    std::string getColour(string colour,bool background);
    // Additional methods for Calendar class
};
