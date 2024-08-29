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


paper::paper(std::string paperName, std::string paperCode, int paperPoints)
    : paperName(paperName), paperCode(paperCode), paperPoints(paperPoints),
      events()
{
}
std::string paper::getPaperName() 
{
    return paperName;
}

std::string paper::getPaperCode() const
{
    return paperCode;
}

int paper::getPaperPoints() 
{
    return paperPoints;
}

// setter methods
void paper::setPaperName(std::string& paperName)
{
    this->paperName = paperName;
}

void paper::setPaperCode(std::string& paperCode)
{
    this->paperCode = paperCode;
}

void paper::setPaperPoints(int paperPoints)
{
    this->paperPoints = paperPoints;
}

void paper::addEvent(eventSkeleton& event)
{
    events.push_back(event);
}

void paper::displayInfo()  {
    cout << "Paper: " << paperName << " (" << paperCode << ")" << endl;
    cout << "Points: " << paperPoints << endl;
    cout << "Events:" << endl;
    for ( auto& event : events) {
        cout << "Event on day " << event.getDay() << " of week " << event.getWeek() << endl;
    }
}
