#include <iostream>
#include <vector>
#include <string>
#include "paper.h"
#include "lecture.h"
#include "tutorial.h"
#include "lab.h"
#include "exam.h"
#include "assignment.h"
#include "eventSkeleton.h"

using namespace std;

// constructor
paper::paper(string paperName, string paperCode, int paperPoints)
    : paperName(paperName), paperCode(paperCode), paperPoints(paperPoints),
      events() // initialize the vectors
{
}

// getter methods
string paper::getPaperName() 
{
    return paperName;
}

string paper::getPaperCode() 
{
    return paperCode;
}

int paper::getPaperPoints() 
{
    return paperPoints;
}

// setter methods
void paper::setPaperName( string& paperName)
{
    this->paperName = paperName;
}

void paper::setPaperCode( string& paperCode)
{
    this->paperCode = paperCode;
}

void paper::setPaperPoints(int paperPoints)
{
    this->paperPoints = paperPoints;
}

// add lecture, tutorial, lab methods
// void paper::addLecture( Lecture& lecture)
// {
//     lectures.push_back(lecture);
// }

// void paper::addTutorial( Tutorial& tutorial)
// {
//     tutorials.push_back(tutorial);
// }

// void paper::addLab( Lab& lab)
// {
//     labs.push_back(lab);
// }
void paper::addEvent(eventSkeleton& event)
{
    events.push_back(event);
}

// display paper information
void paper::displayInfo()  {
    cout << "Paper: " << paperName << " (" << paperCode << ")" << endl;
    cout << "Points: " << paperPoints << endl;
    cout << "Events:" << endl;
    for ( auto& event : events) {
        cout << "Event on day " << event.getDay() << " of week " << event.getWeek() << endl;
    }

    // cout << "Lectures:" << endl;
    // for ( auto& lecture : lectures) {
    //     lecture.displayInfo();
    // }

    // cout << "Labs:" << endl;
    // for ( auto& lab : labs) {
    //     lab.displayInfo();
    // }

    // cout << "Tutorials:" << endl;
    // for ( auto& tutorial : tutorials) {
    //     tutorial.displayInfo();
    // }
}