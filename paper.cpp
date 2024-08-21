#include <iostream>
#include <vector>
#include <string>
#include "paper.h"
#include "lecture.h"
#include "tutorial.h"
#include "lab.h"
#include "exam.h"
#include "assignment.h"

using namespace std;

// constructor
paper::paper(string paperName, string paperCode, int paperPoints)
    : paperName(paperName), paperCode(paperCode), paperPoints(paperPoints),
      lectures(), tutorials(), labs() // initialize the vectors
{
}

// getter methods
string paper::getPaperName() const
{
    return paperName;
}

string paper::getPaperCode() const
{
    return paperCode;
}

int paper::getPaperPoints() const
{
    return paperPoints;
}

// setter methods
void paper::setPaperName(const string &paperName)
{
    this->paperName = paperName;
}

void paper::setPaperCode(const string &paperCode)
{
    this->paperCode = paperCode;
}

void paper::setPaperPoints(int paperPoints)
{
    this->paperPoints = paperPoints;
}

// add lecture, tutorial, lab methods
void paper::addLecture(const Lecture &lecture)
{
    lectures.push_back(lecture);
}

void paper::addTutorial(const Tutorial &tutorial)
{
    tutorials.push_back(tutorial);
}

void paper::addLab(const Lab &lab)
{
    labs.push_back(lab);
}

// display paper information
void paper::displayInfo() const
{
    cout << "Paper: " << paperName << " (" << paperCode << ")" << endl;
    cout << "Points: " << paperPoints << endl;

    cout << "Lectures:" << endl;
    for (const auto &lecture : lectures)
    {
        lecture.displayInfo();
    }

    cout << "Labs:" << endl;
    for (const auto &lab : labs)
    {
        lab.displayInfo();
    }

    cout << "Tutorials:" << endl;
    for (const auto &tutorial : tutorials)
    {
        tutorial.displayInfo();
    }
}