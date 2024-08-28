#include <iostream>
#include <vector>
#include <string>
#include "Calendar.h"
#include "paper.h"
#include "addPaper.h"
#include "eventSkeleton.h"
#include "addNewEvent.h"
#include <limits>
#include "StudySession.h"
#include "MenuItem.h"
using namespace std;
// g++ -o menu menu.cpp
// ./menu

bool running = true;
Calendar* calendar = new Calendar();
vector<paper> papers;
addPaper paperHandler = (papers);

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

// void loadingBar() {
//     std::cout << "Loading menu ";
//     for (int i = 0; i < 20; ++i) {
//         std::cout << "█";
//         std::cout.flush();
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//     }
//     std::cout << std::endl;
// }

// Study session variables
StudySession *studySession = nullptr;

// Menu items
// To add a menu item, add a declaration first here so they are recognised as a function.
void displayMenuOptions();
void startStudySession();
void endStudySession();
void addPaperMenuItem();
void exitMenu();

vector<MenuItem> menuItems = {
    // Add a MenuItem() here, linking to a pointer to the function that manages the item.
    // Do not include the parentheses as it is a pointer to a function.
    // When the user selects the item, it will execute the function.
    MenuItem("Display all menu options", displayMenuOptions),

    // MenuItem("Display all papers.", displayPapers);
    // MenuItem("Display calendar", displayCalendar);
    // MenuItem("Add event", addEvent);
    MenuItem("Start study session", startStudySession),
    MenuItem("End study session", endStudySession),
    // MenuItem("Add paper", addPaperMenuItem);
    MenuItem("Exit", exitMenu)};
void displayMenuOptions()
{
    cout << "\n"
            " ____  _             _         ____  _                             \n"
            "/ ___|| |_ _   _  __| |_   _  |  _ \\| | __ _ _ __  _ __   ___ _ __ \n"
            "\\___ \\| __| | | |/ _` | | | | | |_) | |/ _` | '_ \\| '_ \\ / _ \\ '__|\n"
            " ___) | |_| |_| | (_| | |_| | |  __/| | (_| | | | | | | |  __/ |   \n"
            "|____/ \\__|\\__,_|\\__,_|\\__, | |_|   |_|\\__,_|_| |_|_| |_|\\___|_|   \n"
            "                       |___/                                        \n";
    // cout << "1. Display papers\n";
    // cout << "2. Display calendar\n";
    // cout << "3. Add event\n";
    // cout << "4. Start study session\n";
    // cout << "5. Add paper\n";
    // cout << "6. Exit\n";
    // cout << "7. End study session\n";

    for (size_t i = 0; i < menuItems.size(); ++i)
    {
        cout << i + 1 << ". " << menuItems[i].getName() << "\n";
    }
    cout << "Enter a number: ";
}

void displayMenu()
{
    unsigned int number;
    displayMenuOptions();

    while (running)
    {

        if (cin >> number)
        {
            if (number >= 1 && number <= menuItems.size())
            {
                menuItems[number - 1].execute();
            }
            else
            {
                cout << "Invalid input. Please enter a number between 1 and " << menuItems.size() << "." << endl;
            }
        }
        else
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();                                                   // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    if (running)
    {
        cout << "Press enter to go back to main menu.";
        cin.ignore();
        cin.get();
    }
}
// cout << "input: " << number << endl;

int main()
{
    /**
    displayMenu();
*/
    //paperHandler.addPaperMenu();
     addNewEvent addNewEvent(papers, calendar);
     addNewEvent.addNewEventMenu();
     calendar->display();
    return 0;
}

void startStudySession()
{
    // Start the study session
    if (studySession == nullptr)
    {
        // Ask for paper code, day, and week.
        // TODO: Automatically set day and week and add data validation

        string paperCode;
        int day, week;

        cout << "Enter the paper code: ";
        cin >> paperCode;
        cout << "Enter the day: ";
        cin >> day;
        cout << "Enter the week: ";
        cin >> week;

        studySession = new StudySession(paperCode, day, week);
        studySession->startSession();
    }
    else
    {
        cout << "A study session is already in progress. Please end the current session before starting a new one." << endl;
    }
    cout << "Press 1 to display menu options" << endl;
}

void endStudySession()
{
    // End study session
    if (studySession != nullptr)
    {
        studySession->endSession();
        double duration = studySession->getDuration();
        cout << "Study session duration: " << duration << " seconds." << endl;

        // Now for cleanup
        delete studySession;    // Delete from memory
        studySession = nullptr; // Assign to null pointer.
    }
    else
    {
        // No study sessions are in progress
        cout << "There is not a study session in progress." << endl;
    }
    cout << "Press 1 to display menu options" << endl;
}

void addPaperMenuItem()
{
    // Does nothing at the moment.
    // TODO: add functionality
    return;
}

void exitMenu()
{
    // Exits the program.
    running = false;
    cout << "Exiting menu..." << endl;
}