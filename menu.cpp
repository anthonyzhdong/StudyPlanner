#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Calendar.h"
#include "paper.h"
#include "addPaper.h"
#include "eventSkeleton.h"
#include "addNewEvent.h"
#include "flashcard.h"
#include "flashcardM.h"
#include <limits>
#include "StudySession.h"
#include "MenuItem.h"
#include "validation.h"
#include <iomanip>
#include "CalendarFile.h"
using namespace std;

bool running = true;
Calendar *calendar = new Calendar();
validation validate;

void clearScreen()
{
#ifdef _WIN32
    // For Windows
    std::cout << "\033[2J\033[1;1H";
#else
    // For Unix-like systems
    std::cout << "\033[2J\033[1;1H";
#endif
    std::cout.flush();
}

// Study session variables
StudySession *studySession = nullptr;

// Auto save variable
bool autoSave = false;
std::string *saveFile = nullptr;

// Menu items
// To add a menu item, add a declaration first here so they are recognised as a function.
void displayMenuOptions();
void startStudySession();
void endStudySession();
void addEventMenuItem();
void exitMenu();
void addPaperMenuItem();
void viewCalendarMenuItem();
void saveToFileMenu();
void loadFromFileMenu();
void flashcardMenu();
void autoSaveMenu();
void viewAllPapersMenuItem();
void viewStudyHoursMenuItem();

vector<MenuItem> menuItems = {
    // Add a MenuItem() here, linking to a pointer to the function that manages the item.
    // Do not include the parentheses as it is a pointer to a function.
    // When the user selects the item, it will execute the function.
    MenuItem("Display all menu options", displayMenuOptions),
    MenuItem("View calendar", viewCalendarMenuItem),
    MenuItem("View all papers", viewAllPapersMenuItem),
    MenuItem("Add event", addEventMenuItem),
    MenuItem("Add paper", addPaperMenuItem),
    MenuItem("Start study session", startStudySession),
    MenuItem("End study session", endStudySession),
    MenuItem("Save calendar to file", saveToFileMenu),
    MenuItem("Load calendar from file", loadFromFileMenu),
    MenuItem("Flashcards", flashcardMenu),
    MenuItem("Toggle Auto Save", autoSaveMenu),
    MenuItem("View total study hours", viewStudyHoursMenuItem),
    MenuItem("Exit", exitMenu)};
void displayMenuOptions()
{
    // clearScreen();
    //  commented out to see build errors
    //  clearScreen();

    cout << "\n\033[1m"
            " ____  _             _         ____  _                             \n"
            "/ ___|| |_ _   _  __| |_   _  |  _ \\| | __ _ _ __  _ __   ___ _ __ \n"
            "\\___ \\| __| | | |/ _` | | | | | |_) | |/ _` | '_ \\| '_ \\ / _ \\ '__|\n"
            " ___) | |_| |_| | (_| | |_| | |  __/| | (_| | | | | | | |  __/ |   \n"
            "|____/ \\__|\\__,_|\\__,_|\\__, | |_|   |_|\\__,_|_| |_|_| |_|\\___|_|   \n";

    // for (size_t i = 0; i < menuItems.size(); ++i)
    // {
    //     cout << i + 1 << ". " << menuItems[i].getName() << "\n";
    // }
    // cout << "Enter a number: ";
    const int width = 70;
    const string separator(width, '=');
    const string title = "Study Planner Menu";

    cout << separator << "\n\n";

    for (size_t i = 0; i < menuItems.size(); ++i)
    {
        cout << left << setw(3) << i + 1 << ". " << left << setw(width - 5) << menuItems[i].getName() << "\n";
    }

    cout << "\n"
         << separator << "\n";
    cout << "Enter a number: ";
}

void displayMenu()
{
    int input;
    string p = "";

    displayMenuOptions();

    while (running)
    {

        input = validate.getValidInteger(1, menuItems.size(), p);
        if (input >= 1 && input <= menuItems.size())
        {
            clearScreen();
            menuItems[input - 1].execute();
        }
        else
        {
            cout << "Invalid input. Please enter a number between 1 and " << menuItems.size() << "." << endl;
        }
    }

    if (running)
    {
        cout << "Press enter to go back to main menu.";
        cin.ignore();
        cin.get();
    }
}

int main()
{
    displayMenu();
    return 0;
}

void viewAllPapersMenuItem()
{
    clearScreen();
    if (calendar->getPapers().size() == 0)
    {
        cout << "You have not added any papers." << endl;
    }
    else
    {
        cout << "Papers:" << endl;

        for (auto &p : calendar->getPapers())
        {
            p.displayInfo();
            cout << "---------------------------" << endl;
        }
    }
}

void startStudySession()
{
    clearScreen();
    std::cout << "\n"
                 "  ____  _             _     ____  _             _         ____                _             \n"
                 " / ___|| |_ __ _ _ __| |_  / ___|| |_ _   _  __| |_   _  / ___|  ___  ___ ___(_) ___  _ __  \n"
                 " \\___ \\| __/ _` | '__| __| \\___ \\| __| | | |/ _` | | | | \\___ \\ / _ \\/ __/ __| |/ _ \\| '_ \\ \n"
                 "  ___) | || (_| | |  | |_   ___) | |_| |_| | (_| | |_| |  ___) |  __/\\__ \\__ \\ | (_) | | | |\n"
                 " |____/ \\__\\__,_|_|   \\__| |____/ \\__|\\__,_|\\__,_|\\__, | |____/ \\___||___/___/_|\\___/|_| |_|\n"
                 "                                                  |___/                                      \n";
    if (calendar->getPapers().empty())
    {
        string choicePrompt = "\nYou can't start a study sesion as no papers have been added yet. What would you like to do?\n1. Add a paper\n2. Return to main menu\n";
        int choice = validate.getValidInteger(1, 2, choicePrompt);

        switch (choice)
        {
        case 1:
            addPaperMenuItem();
            break;
        case 2:
            displayMenuOptions();
            break;
        default:
            cout << "Invalid choice. Returning to main menu.\n";
            displayMenuOptions();
            break;
        }
    }
    else
    {
        // Start the study session
        if (studySession == nullptr)
        {
            string paperCode;
            int day, week;

            cout << "Available papers:\n";
            cout << left << setw(8) << "Code" << setw(50) << "Name" << "\n";
            cout << "-----------------------------------------------------";
            // displays paper codes by getting menu's vector<paper> papers
            for (auto &paper : calendar->getPapers())
            {
                cout << "\n"
                     << left << setw(8) << paper.getPaperCode() << setw(50) << paper.getPaperName() << endl;
            }
            cout << "\n-----------------------------------------------------\n";
            paperCode = validate.getValidPaperCode(calendar->getPapers());

            string dayPrompt = "Enter the day of the week (1-7): ";
            string weekPrompt = "Enter the week of the year (1-52): ";

            day = validate.getValidInteger(1, 7, dayPrompt);
            week = validate.getValidInteger(1, 52, weekPrompt);

            studySession = new StudySession(paperCode, day, week);
            studySession->startSession();
        }
        else
        {
            cout << "A study session is already in progress. Please end the current session before starting a new one." << endl;
        }
        cout << "Press 1 to display menu options" << endl;
    }
}

void endStudySession()
{
    clearScreen();
    std::cout << " _____           _   ____  _             _         ____                _             \n"
                 "| ____|_ __   __| | / ___|| |_ _   _  __| |_   _  / ___|  ___  ___ ___(_) ___  _ __ \n"
                 "|  _| | '_ \\ / _` | \\___ \\| __| | | |/ _` | | | | \\___ \\ / _ \\/ __/ __| |/ _ \\| '_ \\ \n"
                 "| |___| | | | (_| |  ___) | |_| |_| | (_| | |_| |  ___) |  __/\\__ \\__ \\ | (_) | | | |\n"
                 "|_____|_| |_|\\__,_| |____/ \\__|\\__,_|\\__,_|\\__, | |____/ \\___||___/___/_|\\___/|_| |_|\n"
                 "                                            |___/                                      \n";
    // End study session
    if (studySession != nullptr)
    {
        studySession->endSession();
        calendar->addEvent(*studySession);
        double duration = studySession->getDuration();
        cout << "Study session duration: " << duration << " seconds." << endl;

        // Now for cleanup
        delete studySession;    // Delete from memory
        studySession = nullptr; // Assign to null pointer.

        if (autoSave)
        {
            CalendarFile::saveToFile(*calendar, *saveFile);
        }
    }
    else
    {
        // No study sessions are in progress so ask user to start one or return to menu
        string choicePrompt = "\nThere isn't a study session in progress. Would you like to begin one?\n1. Start study session\n2. Return to main menu\n";
        int choice = validate.getValidInteger(1, 2, choicePrompt);

        switch (choice)
        {
        case 1:
            startStudySession();
            break;
        case 2:
            displayMenuOptions();
            break;
        default:
            cout << "Invalid choice. Returning to main menu.\n";
            displayMenuOptions();
            break;
        }
    }
}

void addEventMenuItem()
{
    clearScreen();
    std::cout << "\n"
                 "     _       _     _   _____                 _   \n"
                 "    / \\   __| | __| | | ____|_   _____ _ __ | |_ \n"
                 "   / _ \\ / _` |/ _` | |  _| \\ \\ / / _ \\ '_ \\| __|\n"
                 "  / ___ \\ (_| | (_| | | |___ \\ V /  __/ | | | |_ \n"
                 " /_/   \\_\\__,_|\\__,_| |_____| \\_/ \\___|_| |_|\\__|\n"
                 "                                                 \n";
    if (calendar->getPapers().empty())
    {
        string choicePrompt = "No papers have been added yet. What would you like to do?\n1. Add a paper\n2. Return to main menu\n";
        int choice = validate.getValidInteger(1, 2, choicePrompt);

        switch (choice)
        {
        case 1:
            addPaperMenuItem();
            break;
        case 2:
            // clearScreen();
            displayMenuOptions();
            break;
        default:
            cout << "Invalid choice. Returning to main menu.\n";
            // clearScreen();
            displayMenuOptions();
            break;
        }
    }
    else
    {
        addNewEvent newEvent(calendar->getPapers(), calendar);
        newEvent.addNewEventMenu();

        if (autoSave)
        {
            CalendarFile::saveToFile(*calendar, *saveFile);
        }
        cout << "Enter 1 to go back to the main menu" << endl;
    }
}
void addPaperMenuItem()
{
    clearScreen();
    std::cout << "\n"
                 "    _       _     _   ____                       \n"
                 "   / \\   __| | __| | |  _ \\ __ _ _ __   ___ _ __ \n"
                 "  / _ \\ / _` |/ _` | | |_) / _` | '_ \\ / _ \\ '__|\n"
                 " / ___ \\ (_| | (_| | |  __/ (_| | |_) |  __/ |   \n"
                 "/_/   \\_\\__,_|\\__,_| |_|   \\__,_| .__/ \\___|_|   \n"
                 "                                |_|               \n";

    addPaper newPaper(calendar->getPapers());
    newPaper.addPaperMenu();

    if (autoSave)
    {
        CalendarFile::saveToFile(*calendar, *saveFile);
    }
    cout << "Enter 1 to go back to the main menu" << endl;
}

void exitMenu()
{
    // Exits the program.
    running = false;
    cout << "Exiting menu..." << endl;
}

void viewCalendarMenuItem()
{
    clearScreen();
    string choicePrompt = "Type the week you would like to display, or type 0 to display whole year\n";
    int choice = validate.getValidInteger(0, 52, choicePrompt);

    if (choice == 0)
    {
        calendar->display();
    }
    else
    {
        calendar->displayWeek(choice);
    }
    cout << "\nEnter 1 to go back to the main menu" << endl;
}

void autoSaveMenu()
{
    if (saveFile == nullptr)
    {
        cout << "You need to save or load the calendar first!" << endl;
    }
    else
    {

        if (autoSave)
        {
            // Toggle to false
            autoSave = false;
            cout << "Auto save has been disabled." << endl;
        }
        else
        {
            // Toggle to true
            autoSave = true;
            cout << "Auto save has been enabled." << endl;
        }
    }
}

void saveToFileMenu()
{
    string filename;
    cout << "Enter the filename to save the calendar: ";
    cin >> filename;
    if (!CalendarFile::saveToFile(*calendar, filename))
    {
        return;
    }
    if (saveFile == nullptr)
    {
        saveFile = new std::string(filename);
    }
    else
    {
        *saveFile = filename;
    }
    cout << "\nCalendar saved successfully!" << endl;
    cout << "Enter 1 to go back to the main menu" << endl;
}

void loadFromFileMenu()
{
    string filename;
    cout << "Enter the filename to load the calendar: ";
    cin >> filename;

    // Check if the file exists
    ifstream file(filename);
    if (!file.good()) // File does not exist or can't be opened
    {
        cout << "Error: File '" << filename << "' does not exist or cannot be opened." << endl;
    }
    else
    {
        if (!CalendarFile::loadFromFile(*calendar, filename))
        {
            return;
        }
        if (saveFile == nullptr)
        {
            saveFile = new std::string(filename);
        }
        else
        {
            *saveFile = filename;
        }
        cout << "\nCalendar loaded successfully!" << endl;
    }
    file.close();

    cout << "Enter 1 to go back to the main menu" << endl;
}

void flashcardMenu()
{
    flashcardM fcMenu(calendar);
    // checks if papers exist
    if (calendar->getPapers().empty())
    {
        std::string choicePrompt = "\nYou can't view flashcards as no papers have been added yet. What would you like to do?\n1. Add a paper\n2. Return to main menu\n";
        int choice = validate.getValidInteger(1, 2, choicePrompt);

        switch (choice)
        {
        case 1:
            addPaperMenuItem();
            break;
        case 2:
            displayMenuOptions();
            break;
        default:
            cout << "Invalid choice. Returning to main menu.\n";
            displayMenuOptions();
            break;
        }
    }
    else
    {
        // Flashcard menu
        bool flashcardMenuRunning = true;
        while (flashcardMenuRunning)
        {
            std::cout << "Flashcard Menu\n1. View Flashcards\n2. Add Flashcard\n3. Practice Flashcards\n4. Exit\n";
            std::string prompt = "Enter a number: ";
            int choice = validate.getValidInteger(1, 4, prompt);

            switch (choice)
            {
            case 1:
                fcMenu.viewFlashcards();
                while (true)
                {
                    std::cout << "\nPress 'b' to go back to the Flashcard Menu\n";
                    char userInput;
                    std::cin >> userInput;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (userInput == 'b' || userInput == 'B')
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Invalid input. Please try again.\n";
                    }
                }
                break;
            case 2:
                fcMenu.addFlashcard();
                break;
            case 3:
                fcMenu.practiceFlashcards();
                break;
            case 4:
                flashcardMenuRunning = false;
                break;
            }
        }

        displayMenuOptions();
    }
}

void viewStudyHoursMenuItem()
{
    clearScreen();
    std::cout << "\n"
              << " _____     _        _   ____  _             _         _   _                      \n"
              << "|_   _|__ | |_ __ _| | / ___|| |_ _   _  __| |_   _  | | | | ___  _   _ _ __ ___ \n"
              << "  | |/ _ \\| __/ _` | | \\___ \\| __| | | |/ _` | | | | | |_| |/ _ \\| | | | '__/ __|\n"
              << "  | | (_) | || (_| | |  ___) | |_| |_| | (_| | |_| | |  _  | (_) | |_| | |  \\__ \\ \n"
              << "  |_|\\___/ \\__\\__,_|_| |____/ \\__|\\__,_|\\__,_|\\__, | |_| |_|\\___/ \\__,_|_|  |___/\n"
              << "                                               |___/                              \n";

    // Check if there are any papers available
    if (calendar->getPapers().empty())
    {
        std::string choicePrompt = "\nNo papers have been added yet. What would you like to do?\n1. Add a paper\n2. Return to main menu\n";
        int choice = validate.getValidInteger(1, 2, choicePrompt);

        switch (choice)
        {
        case 1:
            addPaperMenuItem();
            break;
        case 2:
            displayMenuOptions();
            break;
        default:
            std::cout << "Invalid choice. Returning to main menu.\n";
            displayMenuOptions();
            break;
        }
    }
    else
    {
        // Prompt user to select a paper
        std::cout << "Select a paper to view study hours:\n";
        std::string paperCode = validate.getValidPaperCode(calendar->getPapers());

        // Prompt user to enter a week number
        std::string weekPrompt = "Enter the week number (1-52): ";
        int week = validate.getValidInteger(1, 52, weekPrompt);

        // Calculate total study hours
        double totalHours = calendar->getTotalStudyHours(paperCode, week);

        // Display the result
        std::cout << "\nTotal hours spent studying paper '" << paperCode << "' in week " << week << ": "
                  << std::fixed << std::setprecision(2) << totalHours << " hours.\n";

        string backPrompt = "\nEnter 1 to go back to the main menu: ";
        validate.getValidInteger(1, 1, backPrompt); // Wait for user to input '1' to return
        displayMenuOptions();
    }
}