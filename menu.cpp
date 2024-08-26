#include <iostream>
#include <vector>
#include <string>
#include "Calendar.h"
#include "Event.h"
#include "AddEvent.h"
#include "paper.h"
#include "addPaper.h"
#include "eventSkeleton.h"
#include "addNewEvent.h"
#include <limits>
#include "StudySession.h"
using namespace std;
// g++ -o menu menu.cpp
// ./menu

Calendar calendar = Calendar();
vector<paper> papers;
addPaper paperHandler = (papers);

// Study session variables
StudySession *studySession = nullptr;

void displayMenuOptions()
{
    cout << "\n"
            " ____  _             _         ____  _                             \n"
            "/ ___|| |_ _   _  __| |_   _  |  _ \\| | __ _ _ __  _ __   ___ _ __ \n"
            "\\___ \\| __| | | |/ _` | | | | | |_) | |/ _` | '_ \\| '_ \\ / _ \\ '__|\n"
            " ___) | |_| |_| | (_| | |_| | |  __/| | (_| | | | | | | |  __/ |   \n"
            "|____/ \\__|\\__,_|\\__,_|\\__, | |_|   |_|\\__,_|_| |_|_| |_|\\___|_|   \n"
            "                       |___/                                        \n";
    cout << "1. Display papers\n";
    cout << "2. Display calendar\n";
    cout << "3. Add event\n";
    cout << "4. Start study session\n";
    cout << "5. Add paper\n";
    cout << "6. Exit\n";
    cout << "7. End study session\n";
}

void displayMenu()
{
    bool running = true;
    int number;

    // basic switch statements using a boolean to control the loop
    while (running)
    {
        displayMenuOptions();
        cout << "Enter a number: ";

        if (cin >> number)
        {
            switch (number)
            {
            case 1:
            {
                // display papers
                cout << "Adding event" << endl;
                // Event e = Event("test", 1, 2, 3, 4);
                // calendar.addEvent(e);

                break;
            }
            case 2:
            {
                // display calendar
                break;
            }
            case 3:
            {
                // add event
                addNewEvent eventHandler(papers);
                eventHandler.addNewEventMenu();

                // AddEvent eventHandler; // Create an instance of AddEvent
                // calendar.addEvent(eventHandler.AddEventMenu());
                break;
            }
            case 4:
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
                break;
            }
            case 5:
            {
                paperHandler.addPaperMenu();

                break;
            }
            case 6:
            {
                // exit
                running = false;
                break;
            }
            case 7:
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
                break;
            }
            default:
                cout << "Invalid input. Please enter an integer." << endl;
                cin.clear();                                                   // Clear error flags
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
        }

        if (running)
        {
            cout << "Press enter to go back to main menu";
            cin.ignore();
            cin.get();
        }
    }
}
// cout << "input: " << number << endl;

int main()
{
    displayMenu();

    return 0;
}
