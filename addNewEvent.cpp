
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
#include "validation.h"
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
    int startTime, endTime, day, week, typeChoice, repeat;

    std::cout << "\n==================== Available Papers ====================\n\n";
    std::cout << "  " << std::left << std::setw(10) << "Code" << std::setw(50) << "Name" << "\n";
    std::cout << "  " << std::string(56, '-') << "\n";

    for (auto &paper : papers)
    {
        std::cout << "  " << std::left 
                << std::setw(10) << paper.getPaperCode() 
                << std::setw(50) << paper.getPaperName() << "\n";
    }

    std::cout << "\n" << std::string(58, '=') << "\n";
    paperCode = validate.getValidPaperCode(papers);

    cout << "Events:\n1. Lecture\n2. Tutorial\n3. Lab\n4. Assignment\n5. Exam\n";
    string typePrompt = "Enter the type of event to add: \n";
    typeChoice = validate.getValidInteger(1, 5, typePrompt);
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
        return;
    }

    // prompts to pass into validator 
    string dayPrompt = "Enter the day of the week (1-7): ";
    string weekPrompt = "Enter the week of the year (1-52): ";
    string assignPrompt = "Enter due time: ";
    string startPrompt = "Enter start time: ";
    string endPrompt = "Enter end time: ";
    string locationPrompt = "Enter location: ";
    string repeatPrompt = "How many weeks should this repeat for? (1 for no repeat): ";

    if (eventType == EventType::ASSIGNMENT)
    {
        endTime = validate.timeValidation(assignPrompt, 0);

        day = validate.getValidInteger(1, 7, dayPrompt);

        week = validate.getValidInteger(1, 52, weekPrompt);
    }
    else
    {
        startTime = validate.timeValidation(startPrompt,0);

        endTime = validate.timeValidation(endPrompt, startTime);

        location = validate.getValidString(locationPrompt);
        
        day = validate.getValidInteger(1, 7, dayPrompt);

        week = validate.getValidInteger(1, 52, weekPrompt);

        repeat = validate.getValidInteger(1, 52, repeatPrompt);
    }

    if (eventType == EventType::TUTORIAL)
    {
        Tutorial newTutorial = Tutorial(paperCode, day, week, startTime, endTime, location);
        if(calendar->addEvent(newTutorial)){
          //  cout << "Event details:\n";
            cout << "\n";
            newTutorial.displayInfo();
            for(auto& p : papers) {
                if(p.getPaperCode() == paperCode) {
                    p.addEvent(newTutorial);
                    break;
                }
            }
        }
        for(int i = 1; i < repeat; i++){
            Tutorial newTutorial = Tutorial(paperCode, day, week+i, startTime, endTime, location);
            calendar->addEvent(newTutorial);
            for(auto& p : papers) {
                if(p.getPaperCode() == paperCode) {
                    p.addEvent(newTutorial);
                    break;
                }
            }
        }
    }else if (eventType == EventType::LAB)
    {
        Lab newLab = Lab(paperCode, day, week, startTime, endTime, location);
        if(calendar->addEvent(newLab)){
           // cout << "Event details:\n";
            cout << "\n";
            newLab.displayInfo();
            for(auto& p : papers) {
                if(p.getPaperCode() == paperCode) {
                    p.addEvent(newLab);
                    break;
                }
            }
        }
        for(int i = 1; i < repeat; i++){
            Lab newLab = Lab(paperCode, day, week+i, startTime, endTime, location);
            calendar->addEvent(newLab);
            for(auto& p : papers) {
                if(p.getPaperCode() == paperCode) {
                    p.addEvent(newLab);
                    break;
                }
            }
        }
    }
    else if (eventType == EventType::LECTURE)
    {
        Lecture newLecture = Lecture(paperCode, day, week, startTime, endTime, location);
        if(calendar->addEvent(newLecture)){
           // cout << "Event details:\n";
            cout << "\n";
            newLecture.displayInfo();
            for(auto& p : papers) {
            if(p.getPaperCode() == paperCode) {
                p.addEvent(newLecture);
                break;
            }
        }
        }
        for(int i = 1; i < repeat; i++){
            Lecture newLecture = Lecture(paperCode, day, week+i, startTime, endTime, location);
            calendar->addEvent(newLecture);
            for(auto& p : papers) {
                if(p.getPaperCode() == paperCode) {
                    p.addEvent(newLecture);
                    break;
                }
            }
        }
    }
    else if (eventType == EventType::ASSIGNMENT)
    {
        Assignment newAssignment = Assignment(paperCode, day, week, startTime, endTime, location);
        calendar->addEvent(newAssignment);
       // cout << "Event details:\n";
        cout << "\n";
        newAssignment.displayInfo();
        for(auto& p : papers) {
            if(p.getPaperCode() == paperCode) {
                p.addEvent(newAssignment);
                break;
            }
        }
    }
    else if (eventType == EventType::EXAM)
    {
        Exam newExam = Exam(paperCode, day, week, startTime, endTime, location);
        calendar->addEvent(newExam);
       // cout << "Event details:\n";
        cout << "\n";
        newExam.displayInfo();
        for(auto& p : papers) {
            if(p.getPaperCode() == paperCode) {
                p.addEvent(newExam);
                break;
            }
        }
    }
    else
    {
        cout << "Invalid event type.";
        return;
    }
    
    
}