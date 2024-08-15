#include <iostream>
#include <string>
#include "Event.h"

class AddEvent
{
public:
    // Method to create an Event object
    Event createEvent(const std::string &name, const std::string &starttime, const std::string &endtime, int day, int week)
    {
        // Assuming starttime and endtime should be converted to int
        int startTimeInt = std::stoi(starttime);
        int endTimeInt = std::stoi(endtime);

        return Event(name, startTimeInt, endTimeInt, day, week);
    }

    void AddEventMenu()
    {
        char choice;
        std::cout << "Would you like to add an event? (y/n): ";
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            std::string name, starttime, endtime;
            int day, week;
            std::cin.ignore(); // To ignore the leftover newline character from previous input
            std::cout << "Enter event name: ";
            std::getline(std::cin, name);
            std::cout << "Enter start time: ";
            std::getline(std::cin, starttime);
            std::cout << "Enter end time: ";
            std::getline(std::cin, endtime);
            std::cout << "Enter day: ";
            std::cin >> day;
            std::cout << "Enter week: ";
            std::cin >> week;

            Event newEvent = createEvent(name, starttime, endtime, day, week);
            // Add the event to the schedule
            // ...
        }
    }
};
