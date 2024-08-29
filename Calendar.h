/**
 * @file Calendar.h
 * @brief Header file for the Calendar class
 */
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
    /**
     * @brief Construct a new Day object
     * @param dayNumber The number of the day
     */
    Day(int dayNumber);
    /**
     * @brief Add an event to the day
     * @param e The event to add
     * @return true if the event was added successfully, false otherwise
     */
    bool addEvent(eventSkeleton& e);

private:
    /**
     * @brief Add an event to the calendar
     * @param d The event to add
     * @return true if the event was added successfully, false otherwise
     */
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
    /**
     * @brief Construct a new Week object
     * @param weekNumber The number of the week
     */
    Week(int weekNumber);
    /**
     * @brief Add an event to the week
     * @param e The event to add
     * @return true if the event was added successfully, false otherwise
     */
    bool addEvent(eventSkeleton& e);

};

/**
 * @class Calendar
 * @brief Represents a calendar, containing multiple weeks.
 */
class Calendar {
private:
    std::vector<Week> weeks;

public:
    /**
     * @brief Construct a new Calendar object
     */
    Calendar();

    /**
     * @brief Display the entire calendar
     */
    void display();

    /**
     * @brief Add an event to the calendar
     * @param e The event to add
     * @return true if the event was added successfully, false otherwise
     */
    bool addEvent(eventSkeleton& e);

    /**
     * @brief Remove an event from the calendar
     * @param e The event to remove
     * @return true if the event was removed successfully, false otherwise
     */
    bool removeEvent(eventSkeleton& e);
    bool editEvent(eventSkeleton& e);
    void displayWeek(int week);
    void displaySemester(int semester);
    bool test();
    std::string getColour(string colour,bool background);
    // Additional methods for Calendar class
};
