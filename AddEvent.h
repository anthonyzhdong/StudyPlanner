#ifndef ADD_EVENT_H
#define ADD_EVENT_H

#include <string>
#include "Event.h"

class AddEvent {
public:
    // Method to create an Event object
    Event createEvent(const std::string &name, const std::string &starttime, const std::string &endtime, int day, int week);

    // Method to display the add event menu and handle user input
    void AddEventMenu();
};

#endif // ADD_EVENT_H