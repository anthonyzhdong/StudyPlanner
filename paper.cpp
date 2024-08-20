#include <iostream>
#include <vector>
#include <string>
#include "paper.h"
#include "lecture.h"
#include "tutorial.h"
#include "lab.h"

// have to include lecture lab and tutorial 
using namespace std;

class Paper
{
public:
    string paperName;
    string paperCode;
    int paperPoints;

    vector<lecture> lectures;
    vector<tutorial> tutorials;
    vector<lab> labs;
    //assignment & exam
    paper(string paperName, string paperCode, int paperPoints)
    {
        this->paperName = paperName;
        this->paperCode = paperCode;
        this->paperPoints = paperPoints;
    }
    // getters
    string getPaperName()
    {
        return paperName;
    }

    string getPaperCode()
    {
        return paperCode;
    }

    int getPaperPoints()
    {
        return paperPoints;
    }

    // setters
    string setPaperName(string& paperName)
    {
        this->paperName = paperName;
    }
    string setPaperCode(string& paperCode)
    {
        this->paperCode = paperCode;
    }
    int setPaperPoints(int paperPoints)
    {
        this->paperPoints = paperPoints;
    }

    // add lecture, tutorial, lab
    void addLecture(const lecture& lecture)
    {
        lectures.push_back(lecture);
    }
    void addTutorial(const tutorial& tutorial)
    {
        tutorials.push_back(tutorial);
    }
    void addLab(const lab& lab)
    {
        labs.push_back(lab);
    }

    // display paper
    void displayInfo() const {
        cout << "Paper: " << paperName << " (" << paperCode << ")" << endl;
        cout << "Points: " << paperPoints << endl;
        
        cout << "Lectures:" << endl;
        for (const auto& lecture : lectures) {
            lecture.displayInfo();
        }
        
        cout << "Labs:" << endl;
        for (const auto& lab : labs) {
            lab.displayInfo();
        }
        
        cout << "Tutorials:" << endl;
        for (const auto& tutorial : tutorials) {
            tutorial.displayInfo();
        }
    }



};