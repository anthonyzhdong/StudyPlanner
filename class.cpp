#include <iostream>
#include <vector>
#include <string>
using namespace std;

class classInfo
{
public:
    string paperName;
    string type;
    string location;
    int day;
    int time;
    classInfo(string paperName, string type, string location, int day, int time)
    {
        this->paperName = paperName;
        this->type = type;
        this->location = location;
        this->day = day;
        this->time = time;
    }
    void displayInfo()
    {
        std::cout << type << " for " << paperName << " at " << location << " on day " << day << " at " << time << std::endl;
    }
};

class Paper
{
public:
    string paperName;
    vector<classInfo> lectures;
    vector<classInfo> tutorials;
    vector<classInfo> labs;
    //assignment & exam

    void addLecture(const classInfo &lecture)
    {
        lectures.push_back(lecture);
    }
    void addTutorial(const classInfo &tutorial)
    {
        tutorials.push_back(tutorial);
    }
    void addLab(const classInfo &lab)
    {
        labs.push_back(lab);
    }

    void setName(const string &name)
    {
        paperName = name;
    }

};