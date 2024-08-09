#include <iostream>
#include <vector>
#include <string>
using namespace std;
// g++ -o menu menu.cpp
// ./menu


class classInfo{
public:
    string paperName;
    string type;
    string location;
    int day;
    int time;
    classInfo(string paperName, string type, string location, int day, int time){
        this->paperName = paperName;
        this->type = type;
        this->location = location;
        this->day = day;
        this->time = time;
    }
    void displayInfo(){
        std::cout << type << " for " << paperName << " at " << location << " on day " << day << " at " << time << std::endl;
    }
};

class assignment{
public:
    string assignmentName;
    string overview;
    string paperName;
    int dueDate;
    int grade;
    assignment(string assignmentName, string overview, string paperName, int dueDate, int grade){
        this->assignmentName = assignmentName;
        this->overview = overview;
        this->paperName = paperName;
        this->dueDate = dueDate;
        this->grade = grade;
    }
};

class Paper {
public:
    string paperName;
    vector<classInfo> lectures;
    vector<classInfo> tutorials;
    vector<classInfo> labs;
    vector<assignment> assignments;

    void addLecture(const classInfo& lecture){
        lectures.push_back(lecture);
    }
    void addTutorial(const classInfo& tutorial){
        tutorials.push_back(tutorial);
    }
    void addLab(const classInfo& lab){
        labs.push_back(lab);
    }
    void addAssignment(const assignment& assignment){
        assignments.push_back(assignment);
    }

    void displayPaperInfo(){
        std::cout << "Paper: " << paperName << std::endl;
        std::cout << "Lectures: " << std::endl;
        for (int i = 0; i < lectures.size(); i++){
            lectures[i].displayInfo();
        }
        std::cout << "Tutorials: " << std::endl;
        for (int i = 0; i < tutorials.size(); i++){
            tutorials[i].displayInfo();
        }
        std::cout << "Labs: " << std::endl;
        for (int i = 0; i < labs.size(); i++){
            labs[i].displayInfo();
        }
        std::cout << "Assignments: " << std::endl;
        for (int i = 0; i < assignments.size(); i++){
            std::cout << "Assignment: " << assignments[i].assignmentName << " for " << assignments[i].paperName << " due on day " << assignments[i].dueDate << " with grade " << assignments[i].grade << std::endl;
        }
    }


};

void displayMenu(){
    cout << "\n===== Paper Management System =====\n";
    cout << "test\n";
}
    

int main() {
    displayMenu();
    //test data
    // Create a new paper
    Paper compSci;
    compSci.paperName = "CS101: Introduction to Computer Science";

    // Add lectures
    compSci.addLecture(classInfo("Intro to CS", "Lecture", "Room 101", 1, 900));
    compSci.addLecture(classInfo("Intro to CS", "Lecture", "Room 101", 3, 900));

    // Add labs
    compSci.addLab(classInfo("Intro to CS", "Lab", "Lab Room 201", 2, 1300));
    compSci.addLab(classInfo("Intro to CS", "Lab", "Lab Room 201", 4, 1300));

    // Add tutorials
    compSci.addTutorial(classInfo("Intro to CS", "Tutorial", "Room 301", 2, 1500));
    compSci.addTutorial(classInfo("Intro to CS", "Tutorial", "Room 301", 4, 1500));

    // Add assignments
    compSci.addAssignment(assignment("Programming Basics", "Write a simple program", "Intro to CS", 14, 0));
    compSci.addAssignment(assignment("Data Structures", "Implement a linked list", "Intro to CS", 28, 0));

    // Display all information about the paper
    //compSci.displayPaperInfo();

    return 0;
}

