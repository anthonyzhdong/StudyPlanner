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
    vector<Lecture> lectures;
    vector<Tutorial> tutorials;
    vector<Lab> labs;

public:
    // constructor
    paper(string paperName, string paperCode, int paperPoints);

    // getter methods
    string getPaperName() const;
    string getPaperCode() const;
    int getPaperPoints() const;

    // setter methods
    void setPaperName(const string& paperName);
    void setPaperCode(const string& paperCode);
    void setPaperPoints(int paperPoints);

    // add classes methods
    void addLecture(const Lecture& lecture);
    void addTutorial(const Tutorial& tutorial);
    void addLab(const Lab& lab);

    // display paper information
    void displayInfo() const;
};
