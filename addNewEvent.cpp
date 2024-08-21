
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "addNewEvent.h"
#include "tutorial.h"
#include "lab.h"
#include "lecture.h"
#include "Calendar.h"
#include "eventSkeleton.h"


using namespace std;
    vector<eventSkeleton> events;
// enum class EventType {
//     TUTORIAL,
//     LAB,
//     LECTURE,
//     ASSIGNMENT,
//     EXAM,
//     STUDY_SESSION
// };

void addNewEvent::addNewEventMenu() {
    string paperCode, eventType, location;
    int startTime, endTime, day, week;
    // any more variables for exams/assignments/study session?


    cout << "Choose paper code";
    // displays paper codes by getting menu's vector<paper> papers
    cin >> paperCode;
    cout << "Choose type: (tutorial, lab, lecture)";
    // use enum
    cin >> eventType;
    //depending on type/enum, ask for certain properties -> we've only implemented 3 which share the same traits
    cout << "Enter start time: ";
    cin >> startTime;
    cout << "Enter end time: ";
    cin >> endTime;
    cout << "Enter location: ";
    cin >> location;
    cout << "Enter day: ";
    cin >> day;
    // may need to also ask for range of weeks? - can sort out later
    cout << "Enter week: ";
    cin >> week;
    // if assignment -> ask for x variables
    // if exam -> ask for x variables
    // if study session -> ask for x variables

    // creation of object depending on event type
    // if eventType == tutorial 
    Tutorial newTutorial = Tutorial(eventType, paperCode, startTime, endTime, location, day, week);
    // else if eventType == lab
    //lab newLab = lab(eventType, paperCode, startTime, endTime, location, day, week);
    // else if eventType == lecture
    //lecture newLecture = lecture(eventType, paperCode, startTime, endTime, location, day, week);

    // add this object to event wrapper which is a generic using eventType
    events.push_back(newTutorial);
    }





