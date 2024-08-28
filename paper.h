#include <string>
#include <vector>
#include "lecture.h"
#include "tutorial.h"
#include "lab.h"
#pragma once

using namespace std;

class paper {
private:
    string paperName;
    string paperCode;
    int paperPoints;
    // vector<Lecture> lectures;
    // vector<Tutorial> tutorials;
    // vector<Lab> labs;
    vector<eventSkeleton> events;

public:
    // constructor
    paper(string paperName, string paperCode, int paperPoints);

    // getter methods
    string getPaperName() ;
    string getPaperCode() const;
    int getPaperPoints() ;

    // setter methods
    void setPaperName( string& paperName);
    void setPaperCode( string& paperCode);
    void setPaperPoints(int paperPoints);

    // add classes methods
    // void addLecture( Lecture& lecture);
    // void addTutorial( Tutorial& tutorial);
    // void addLab( Lab& lab);
    void addEvent(eventSkeleton& event);

    // display paper information
    void displayInfo() ;
};
