
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

// Constructor to initialize papers
addNewEvent::addNewEvent(vector<paper> &papers, Calendar *calendar) : papers(papers), calendar(calendar)
{
}

vector<eventSkeleton> addNewEvent::getEvents()
{
    return events;
}
void addNewEvent::addNewEventMenu()
{
    EventType eventType;
    string paperCode, location;
    int startTime, endTime, day, week, typeChoice;

    cout << "Available papers:\n";
    cout << left << setw(8) << "Code" << setw(50) << "Name" << "\n";
    cout << "-------------------------------------------------------";
    // displays paper codes by getting menu's vector<paper> papers
    for (auto &paper : papers)
    {
        cout << "\n" << left << setw(8) << paper.getPaperCode() << setw(50) << paper.getPaperName() << endl;
    }
    cout << "\n-----------------------------------------------------";
    cout << "\nPlease enter the paper code: ";
    cin >> paperCode;


    // Returns if the paper code is valid.
    auto it = find_if(papers.begin(), papers.end(), [&paperCode](const paper &paperObj) {
        return paperObj.getPaperCode() == paperCode;
    });

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
    string dayPrompt = "Enter the day of the week (1-7): ";
    string weekPrompt = "Enter the week of the year (1-52): ";
    string assignPrompt = "Enter due time: ";
    string startPrompt = "Enter start time: ";
    string endPrompt = "Enter end time: ";
    string locationPrompt = "Enter location: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (eventType == EventType::ASSIGNMENT)
    {
        endTime = validator.timeValidation(assignPrompt, 0);

        day = validator.getValidInteger(1, 7, dayPrompt);

        week = validator.getValidInteger(1, 52, weekPrompt);
    }
    else
    {
        startTime = validator.timeValidation(startPrompt,0);

        endTime = validator.timeValidation(endPrompt, startTime);

        location = validator.getValidString(locationPrompt);
        
        day = validator.getValidInteger(1, 7, dayPrompt);

        week = validator.getValidInteger(1, 52, weekPrompt);
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