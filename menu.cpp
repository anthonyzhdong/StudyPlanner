#include <iostream>
#include <vector>
#include <string>
#include "Calendar.h"
#include "Event.h"
#include "AddEvent.h"
#include "paper.h"
#include "addPaper.h"
#include <limits>
using namespace std;
// g++ -o menu menu.cpp
// ./menu

Calendar calendar = Calendar();
vector<paper> papers;
addPaper paperHandler = (papers);

void displayMenu()
{
    cout << "\n"
            " ____  _             _         ____  _                             \n"
            "/ ___|| |_ _   _  __| |_   _  |  _ \\| | __ _ _ __  _ __   ___ _ __ \n"
            "\\___ \\| __| | | |/ _` | | | | | |_) | |/ _` | '_ \\| '_ \\ / _ \\ '__|\n"
            " ___) | |_| |_| | (_| | |_| | |  __/| | (_| | | | | | | |  __/ |   \n"
            "|____/ \\__|\\__,_|\\__,_|\\__, | |_|   |_|\\__,_|_| |_|_| |_|\\___|_|   \n"
            "                       |___/                                        \n";
    // cout << "Type a command and press enter.\n";
    // cout << "Display item(s): display <papers|lectures|labs|tutorials|assignments>\n";
    // cout << "Add an item: add <paper|lecture|lab|tutorial|assignment>\n"; // After typing this, prompt the user to add details.
    // cout << "Remove an item: remove <paper|lecture|lab|tutorial|assignment>"; // After typing this, prompt the user to add details of what to delete.
    cout << "1. Display papers\n";
    cout << "2. Display calendar\n";
    cout << "3. Add event\n";
    cout << "4. Start study session\n";
    cout << "5. Add paper\n";
    cout << "6. Exit\n";
    int number;

    // have to figure out how to switch between states
    while (true)
    {
        if (cin >> number)
        {
            switch (number)
            {
            case 1:
            {
                // display papers
                // cout << "Adding event" << endl;
                // Event e = Event("test", 1, 2, 3, 4);
                // calendar.addEvent(e);
                break;
            }
            case 2:
            {
                // Display calendar
                break;
            }
            case 3:
            {
                // Add event
                // AddEvent eventHandler; // Create an instance of AddEvent
                // calendar.addEvent(eventHandler.AddEventMenu());

                break;
            }
            case 4:
            {
                // Start study session
                break;
            }
            case 5:
            {
                // add paper
                // cout << "hello" << endl;
                paperHandler.addPaperMenu();

                break;
            }
            case 6:
            {
                // Exit
                break;
            }
            default:
                cout << "Invalid input. Please enter an integer." << endl;
                cin.clear();                                                   // Clear error flags
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
        }
        else
        {

            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();                                                   // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input}
            // cout << "input: " << number << endl;
        }
    }
}

int main()
{
    displayMenu();

    return 0;
}
