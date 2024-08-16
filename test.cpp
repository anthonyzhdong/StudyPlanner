#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <string>
// macos /linux
int getTerminalWidth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int main() {
    int width = getTerminalWidth();
    std:: string s = "menu";

    if(width %2 != 0){
        width-=1;
    }
    int half = (width/2) - 2;
    std::cout << half << std::endl;
    std::cout << std::string(half, '-') << s << std::string(half, '-') << std::endl;

    std::cout << "The current terminal width is: " << width << " characters." << std::endl;
    
    // Demonstrate the width by printing a line of characters
    std::cout << std::string(width, '-') << std::endl;
    
    return 0;
}
// #include <windows.h>

// int getTerminalWidth() {
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//     return csbi.srWindow.Right - csbi.srWindow.Left + 1;
// }

// class classInfo
// {
// public:
//     string paperName;
//     string type;
//     string location;
//     int day;
//     int time;
//     classInfo(string paperName, string type, string location, int day, int time)
//     {
//         this->paperName = paperName;
//         this->type = type;
//         this->location = location;
//         this->day = day;
//         this->time = time;
//     }
//     void displayInfo()
//     {
//         std::cout << type << " for " << paperName << " at " << location << " on day " << day << " at " << time << std::endl;
//     }
// };

// class assignment
// {
// public:
//     string assignmentName;
//     string overview;
//     string paperName;
//     int dueDate;
//     int grade;
//     assignment(string assignmentName, string overview, string paperName, int dueDate, int grade)
//     {
//         this->assignmentName = assignmentName;
//         this->overview = overview;
//         this->paperName = paperName;
//         this->dueDate = dueDate;
//         this->grade = grade;
//     }
// };

// class Paper
// {
// public:
//     string paperName;
//     vector<classInfo> lectures;
//     vector<classInfo> tutorials;
//     vector<classInfo> labs;
//     vector<assignment> assignments;

//     void addLecture(const classInfo &lecture)
//     {
//         lectures.push_back(lecture);
//     }
//     void addTutorial(const classInfo &tutorial)
//     {
//         tutorials.push_back(tutorial);
//     }
//     void addLab(const classInfo &lab)
//     {
//         labs.push_back(lab);
//     }
//     void addAssignment(const assignment &assignment)
//     {
//         assignments.push_back(assignment);
//     }

//     void setName(const string &name)
//     {
//         paperName = name;
//     }

//     void displayPaperInfo()
//     {
//         std::cout << "\nPaper: " << paperName << std::endl;
//         std::cout << "Lectures: " << std::endl;
//         for (int i = 0; i < lectures.size(); i++)
//         {
//             lectures[i].displayInfo();
//         }
//         std::cout << "Tutorials: " << std::endl;
//         for (int i = 0; i < tutorials.size(); i++)
//         {
//             tutorials[i].displayInfo();
//         }
//         std::cout << "Labs: " << std::endl;
//         for (int i = 0; i < labs.size(); i++)
//         {
//             labs[i].displayInfo();
//         }
//         std::cout << "Assignments: " << std::endl;
//         for (int i = 0; i < assignments.size(); i++)
//         {
//             std::cout << "Assignment: " << assignments[i].assignmentName << " for " << assignments[i].paperName << " due on day " << assignments[i].dueDate << " with grade " << assignments[i].grade << std::endl;
//         }
//     }
// };