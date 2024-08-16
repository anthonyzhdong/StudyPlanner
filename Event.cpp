#include "Calendar.h"
#include "Event.h"
#include <string>
#include <iostream>

using namespace std;

class event
{

public:
    string eventName;
    int startTime;
    int endTime;
    int day;
    int week;
    event(string eventName, int startTime, int endTime, int day, int week)
    {
        this->eventName = eventName;
        this->startTime = startTime;
        this->endTime = endTime;
        this->day = day;
        this->week = week;
    }

    string getEventName()
    {
        return eventName;
    }
    int getStartTime()
    {
        return startTime;
    }
    int getEndTime()
    {
        return endTime;
    }

    int getDay()
    {
        return day;
    }

    int getWeek()
    {
        return week;
    }

    // void addEventToCalendar(Calendar& calendar)
    // {
    //     Event e(eventName, startTime, endTime);
    //     calendar.addEvent(e);
    // }
}
