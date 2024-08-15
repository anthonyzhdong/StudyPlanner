#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>

// Forward declaration of classes
class Event;
class Day;
class Week;
class Calendar;

// Event class definition
class Event {
    // Event class implementation details
};

// Day class definition
class Day {
private:
    std::vector<Event> events;
    int dayNumber;

public:
    Day(int dayNumber);
    // Additional methods for Day class
};

// Week class definition
class Week {
private:
    std::vector<Day> days;
    int weekNumber;

public:
    Week(int weekNumber);
    // Additional methods for Week class
};

// Calendar class definition
class Calendar {
private:
    std::vector<Week> weeks;

public:
    Calendar();
    void display();
    bool addEvent(const Event& e);
    bool removeEvent(const Event& e);
    bool editEvent(const Event& e);
    // Additional methods for Calendar class
};

#endif // CALENDAR_H

