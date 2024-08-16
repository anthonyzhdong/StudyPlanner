#include <iostream>
#include <string>
#include "Event.cpp"

class AddEvent
{
public:
    // Method to create an Event object
    event createEvent(const std::string &name, const std::string &starttime, const std::string &endtime, int day, int week)
    {
        // Assuming starttime and endtime should be converted to int
        int startTimeInt = std::stoi(starttime);
        int endTimeInt = std::stoi(endtime);
        Event e(name, startTimeInt, endTimeInt, day, week);
        return e;
    }

    Event AddEventMenu()
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

            // Start time input and validation
            std::cout << "Enter start time (0000-2400): ";
            while (true)
            {
                std::cin >> starttime;
                try
                {
                    if (starttime.length() == 4 && std::stoi(starttime) >= 0 && std::stoi(starttime) <= 2400)
                    {
                        break;
                    }
                }
                catch (std::invalid_argument &)
                {
                    // Handle the case where the input is not an integer
                }
                std::cout << "Invalid time. Please enter a number between 0000 and 2400: ";
            }

            // End time input and validation
            std::cout << "Enter end time (0000-2400): ";
            while (true)
            {
                std::cin >> endtime;
                try
                {
                    if (endtime.length() == 4 && std::stoi(endtime) >= 0 && std::stoi(endtime) <= 2400)
                    {
                        // Check if end time is not less than start time
                        if (std::stoi(endtime) >= std::stoi(starttime))
                        {
                            break;
                        }
                        else
                        {
                            std::cout << "End time cannot be less than start time. Please enter a valid end time: ";
                        }
                    }
                    else
                    {
                        std::cout << "Invalid time. Please enter a number between 0000 and 2400: ";
                    }
                }
                catch (std::invalid_argument &)
                {
                    // Handle the case where the input is not an integer
                    std::cout << "Invalid input. Please enter a number between 0000 and 2400: ";
                }
            }

            // Day input and validation
            std::cout << "Enter day (0-7): ";
            while (true)
            {
                std::cin >> day;
                if (day >= 0 && day <= 7)
                {
                    break;
                }
                std::cout << "Invalid day. Please enter a number between 0 and 7: ";
            }

            std::cout << "Enter week: ";
            std::cin >> week;

            event newEvent = createEvent(name, starttime, endtime, day, week);
            // Add the event to the schedule
            // ...

            return newEvent;
        }
        //return std::nullopt;
    }
};