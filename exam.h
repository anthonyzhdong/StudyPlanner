#include <string>
#pragma once

using namespace std;

class Exam
{
private:
    string paperCode;
    int startTime;
    int endTime;
    string location;
    int date;

public:
    // constructor
    Exam(string paperCode, int startTime, int endTime, string location, int date);

    // getter methods
    string getPaperCode() const;
    int getStartTime() const;
    int getEndTime() const;
    string getLocation() const;
    int getDate() const;

    // setter methods
    void setPaperCode(const string &paperCode);
    void setStartTime(int startTime);
    void setEndTime(int endTime);
    void setLocation(const string &location);
    void setDate(int date);

    // displays exam information
    void displayInfo() const;
};