
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

using namespace std;

vector<eventSkeleton> events;

int timeValidation(const string &prompt, int minTime = 0)
{
    int time;
    bool valid = false;
    while (!valid)
    {
        cout << prompt;
        cin >> time;
        if (time < 0 || time > 2359 || (time % 100) >= 60)
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

int dayValidation()
{
    int day;
    bool valid = false;
    while (!valid)
    {
        cout << "Enter day between 0 (Sunday) and 7 (Saturday): ";
        cin >> day;
        if (day < 0 || day > 7)
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

int weekValidation()
{
    int week;
    bool valid = false;
    while (!valid)
    {
        cout << "Enter week between 0 and 52: ";
        cin >> week;
        if (week < 0 || week > 52)
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
addNewEvent::addNewEvent(vector<paper> &papers) : papers(papers)
{
}

void addNewEvent::addNewEventMenu()
{
    EventType eventType;
    string paperCode, location;
    int startTime, endTime, day, week, typeChoice;

    cout << "Choose paper code:\n";
    // displays paper codes by getting menu's vector<paper> papers
    int index = 1;
    for (auto &paper : papers)
    {
        cout << index << ". " << paper.getPaperCode() << " - " << paper.getPaperName() << "\n"
             << endl;
        index++;
    }
    cin >> paperCode;

    cout << "Choose the type of event to add:\n1. Lecture\n2. Tutorial\n3. Lab\n4. Assignment\n5. Exam\n";
    while (true)
    {
        cin >> typeChoice;
        if (typeChoice < 1 || typeChoice > 5)
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
        events.push_back(newTutorial);
    }
    else if (eventType == EventType::LAB)
    {
        Lab newLab = Lab(paperCode, day, week, startTime, endTime, location);
        events.push_back(newLab);
    }
    else if (eventType == EventType::LECTURE)
    {
        Lecture newLecture = Lecture(paperCode, day, week, startTime, endTime, location);
        events.push_back(newLecture);
    }
    else if (eventType == EventType::ASSIGNMENT)
    {
        Assignment newAssignment = Assignment(paperCode, day, week, startTime, endTime, location);
        events.push_back(newAssignment);
    }
    else if (eventType == EventType::EXAM)
    {
        Exam newExam = Exam(paperCode, day, week, startTime, endTime, location);
        events.push_back(newExam);
    }
    else
    {
        cout << "Invalid event type.";
    }
}
