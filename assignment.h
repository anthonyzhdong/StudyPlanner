#include <string>
#pragma once

using namespace std;

class Assignment
{
private:
    string paperCode;
    string assignmentName;
    int dueTime;
    int dueDate;

public:
    // constructor
    Assignment(string paperCode, string assignmentName, int dueTime, int dueDate);

    // getter methods
    string getPaperCode() const;
    string getAssignmentName() const;
    int getDueTime() const;
    int getDueDate() const;

    // setter methods
    void setPaperCode(const string &paperCode);
    void setAssignmentName(const string &assignmentName);
    void setDueTime(int dueTime);
    void setDueDate(int dueDate);

    // displays assignment information
    void displayInfo() const;
};