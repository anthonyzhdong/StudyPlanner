#include "Calendar.h"
#include "Event.h"
#include <string>
#include <iostream>

using namespace std;

class event{

public:
    string eventName;
    int startTime;
    int endTime;
    event(string eventName, int startTime, int endTime){
        this->eventName = eventName;
        this->startTime = startTime;
        this->endTime = endTime;
    }

    string getEventName(){
        return eventName;
    }
    string getStartTime(){
        return startTime;
    }
    string getEndTime(){
        return endTime;
    }

    // void addEventToCalendar(Calendar& calendar)
    // {
    //     Event e(eventName, startTime, endTime);
    //     calendar.addEvent(e);
    // }






}
