
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "addNewEvent.h"
#include "tutorial.h"
#include "lab.h"
#include "assignment.h"
#include "exam.h"
#include "lecture.h"
#include "Calendar.h"
#include "eventSkeleton.h"
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<eventSkeleton> events;

/**
 * @brief Validates and retrieves a time input from the user.
 *
 * This function prompts the user to enter a time in the 24-hour format (e.g., 0930 for 9:30 AM).
 * It ensures the input is an integer, within the valid time range (0000-2359), and the minutes part is less than 60.
 * Additionally, it checks that the time is greater than or equal to the specified minimum time.
 *
 * @param prompt The message displayed to the user for input.
 * @param minTime The minimum valid time that can be entered (default is 0).
 * @return int The validated time in 24-hour format.
 */
int timeValidation(const string &prompt, int minTime = 0)
{
    int time;
    bool valid = false;
    while (!valid)
    {
        cout << prompt;
        cin >> time;
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            cout << "Invalid input. Please enter a valid integer for time.\n";
        }
        else if (time < 0 || time > 2359 || (time % 100) >= 60)
        {
            cout << "Invalid time. Please enter a valid 24-hour time (e.g., 0930 for 9:30 AM, 1430 for 2:30 PM).\n";
        }
        else if (time < minTime)
        {
            cout << "Invalid time. Time must be greater than or equal to start time of " << minTime << ".\n";
        }
        else
        {
            valid = true;
        }
    }
    return time;
}


/**
 * @brief Validates and retrieves a day input from the user.
 *
 * This function prompts the user to enter a day of the week, where 0 represents Sunday and 7 represents Saturday.
 * It ensures the input is an integer within the valid day range (0-7).
 *
 * @param none
 * @return int The validated day as an integer.
 */
int dayValidation()
{
    int day;
    bool valid = false;
    while (!valid)
    {
        cout << "Enter day between 0 (Sunday) and 7 (Saturday): ";
        cin >> day;
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            cout << "Invalid input. Please enter a valid integer for day.\n";
        }
        else if (day < 0 || day > 7)
        {
            cout << "Invalid day. Please enter a day between 0 (Sunday) and 7 (Saturday).\n";
        }
        else
        {
            valid = true;
        }
    }
    return day;
}
/**
 * @brief Validates and retrieves a week input from the user.
 *
 * This function prompts the user to enter a week number, ensuring it is within the valid range (0-52).
 *
 * @param none
 * @return int The validated week number as an integer.
 */
int weekValidation()
{
    int week;
    bool valid = false;
    while (!valid)
    {
        cout << "Enter week between 0 and 52: ";
        cin >> week;
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            cout << "Invalid input. Please enter a valid integer for week.\n";
        }
        else if (week < 0 || week > 52)
        {
            cout << "Invalid week. Please enter a positive integer between 0 and 52.\n";
        }
        else
        {
            valid = true;
        }
    }
    return week;
}

// enum lecture, tutorial, lab, assignment, exam

// Constructor to initialize papers
addNewEvent::addNewEvent(vector<paper> &papers, Calendar *calendar) : papers(papers), calendar(calendar)
{
}

vector<eventSkeleton> addNewEvent::getEvents()
{
    return events;
}

/**
 * @brief Displays the menu for adding a new event and handles user input.
 *
 * This function presents a menu to the user to select a paper and the type of event they wish to add.
 * Based on the event type, it prompts for the appropriate details (e.g., time, day, week) and adds the event to the Calendar.
 *
 * @param none
 * @return none
 */
void addNewEvent::addNewEventMenu()
{
    EventType eventType;
    string paperCode, location;
    int startTime, endTime, day, week, typeChoice;
    while (true)
    {
        cout << "Available papers:\n";
        cout << left << setw(8) << "Code" << setw(50) << "Name" << "\n";
        cout << "-------------------------------------------------------";
        // displays paper codes by getting menu's vector<paper> papers
        for (auto &paper : papers)
        {
            cout << "\n"
                 << left << setw(8) << paper.getPaperCode() << setw(50) << paper.getPaperName() << endl;
        }
        cout << "\n-----------------------------------------------------";
        cout << "\nPlease enter the paper code: ";
        cin >> paperCode;

        // Returns if the paper code is valid.
        auto it = find_if(papers.begin(), papers.end(), [&paperCode](const paper &paperObj)
                          { return paperObj.getPaperCode() == paperCode; });

        if (it != papers.end())
        {
            cout << "You selected: " << it->getPaperName() << endl;
            break;
        }
        else
        {
            cout << "Invalid paper code, please try again.\n";
        }
    }

    cout << "Choose the type of event to add:\n1. Lecture\n2. Tutorial\n3. Lab\n4. Assignment\n5. Exam\n";
    while (true)
    {
        cin >> typeChoice;
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            cout << "Invalid input. Please enter a valid integer for week.\n";
        }
        else if (typeChoice < 1 || typeChoice > 5)
        {
            cout << "Invalid choice. Please choose a number between 1 and 5.\n";
        }
        else
        {
            break;
        }
    }
    // need to add input validation if they put outside of input range
    switch (typeChoice)
    {
    case 1:
        eventType = EventType::LECTURE;
        break;
    case 2:
        eventType = EventType::TUTORIAL;
        break;
    case 3:
        eventType = EventType::LAB;
        break;
    case 4:
        eventType = EventType::ASSIGNMENT;
        break;
    case 5:
        eventType = EventType::EXAM;
        break;
    default:
        cout << "bad input";
    }

    // depending on type/enum, ask for properties tied to specific event e.g. lecture has different properties to assignment

    if (eventType == EventType::ASSIGNMENT)
    {
        endTime = timeValidation("Enter due time: ");

        day = dayValidation();

        week = weekValidation();
    }
    else
    {
        startTime = timeValidation("Enter start time: ");

        endTime = timeValidation("Enter end time: ", startTime);

        cout << "Enter location: ";
        cin >> location;

        day = dayValidation();

        week = weekValidation();
    }

    // pseudo
    if (eventType == EventType::TUTORIAL)
    {
        Tutorial newTutorial = Tutorial(paperCode, day, week, startTime, endTime, location);
        calendar->addEvent(newTutorial);
    }
    else if (eventType == EventType::LAB)
    {
        Lab newLab = Lab(paperCode, day, week, startTime, endTime, location);
        calendar->addEvent(newLab);
    }
    else if (eventType == EventType::LECTURE)
    {
        Lecture newLecture = Lecture(paperCode, day, week, startTime, endTime, location);
        calendar->addEvent(newLecture);
    }
    else if (eventType == EventType::ASSIGNMENT)
    {
        Assignment newAssignment = Assignment(paperCode, day, week, startTime, endTime, location);

        calendar->addEvent(newAssignment);
    }
    else if (eventType == EventType::EXAM)
    {
        Exam newExam = Exam(paperCode, day, week, startTime, endTime, location);
        calendar->addEvent(newExam);
    }
    else
    {
        cout << "Invalid event type.";
    }
}
