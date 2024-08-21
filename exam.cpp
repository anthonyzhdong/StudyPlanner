#include <iostream>
#include "exam.h"

using namespace std;

// constructor
Exam::Exam(string paperCode, int startTime, int endTime, string location, int date)
    : paperCode(paperCode), startTime(startTime), endTime(endTime), location(location), date(date)
{
}

// getter methods
string Exam::getPaperCode() const
{
    return paperCode;
}

int Exam::getStartTime() const
{
    return startTime;
}

int Exam::getEndTime() const
{
    return endTime;
}

std::string Exam::getLocation() const
{
    return location;
}

int Exam::getDate() const
{
    return date;
}

// setter methods

void Exam::setPaperCode(const string &paperCode)
{
    this->paperCode = paperCode;
}

void Exam::setStartTime(int startTime)
{
    this->startTime = startTime;
}

void Exam::setEndTime(int endTime)
{
    this->endTime = endTime;
}

void Exam::setLocation(const string &location)
{
    this->location = location;
}

void Exam::setDate(int date)
{
    this->date = date;
}

// displays exam information
void Exam::displayInfo() const
{
    cout << "Paper Code: " << paperCode << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Location: " << location << endl;
    cout << "Date: " << date << endl;
}