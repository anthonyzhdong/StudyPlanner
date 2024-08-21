#include <iostream>
#include "assignment.h"

using namespace std;

// constructor
Assignment::Assignment(string paperCode, string assignmentName, int dueTime, int dueDate)
    : paperCode(paperCode), assignmentName(assignmentName), dueTime(dueTime), dueDate(dueDate)
{
}

// getter methods
string Assignment::getPaperCode() const
{
    return paperCode;
}

string Assignment::getAssignmentName() const
{
    return assignmentName;
}

int Assignment::getDueTime() const
{
    return dueTime;
}

int Assignment::getDueDate() const
{
    return dueDate;
}

// setter methods

void Assignment::setPaperCode(const string &paperCode)
{
    this->paperCode = paperCode;
}

void Assignment::setAssignmentName(const string &assignmentName)
{
    this->assignmentName = assignmentName;
}

void Assignment::setDueTime(int dueTime)
{
    this->dueTime = dueTime;
}

void Assignment::setDueDate(int dueDate)
{
    this->dueDate = dueDate;
}

// displays assignment information
void Assignment::displayInfo() const
{
    cout << "Assignment Name: " << assignmentName << endl;
    cout << "Paper Code: " << paperCode << endl;
    cout << "Due Time: " << dueTime << endl;
    cout << "Due Date: " << dueDate << endl;
}
