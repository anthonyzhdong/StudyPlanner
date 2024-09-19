#include <vector>
#include <iostream>
#include "Calendar.h"
#include "eventSkeleton.h"
#include "lecture.h"
#include "lab.h"
#include "assignment.h"
#include "exam.h"
#include "tutorial.h"
#include <iomanip>
#include <sstream>
#include "paper.h"
#include <map>
#include "addNewEvent.h"

using namespace std;

Day::Day(int dayNumber) : dayNumber(dayNumber)
{
}

bool Day::addEvent(eventSkeleton &d)
{
    if (d.getEventType() ==EventType::ASSIGNMENT)
    {
        assignments.push_back(static_cast<Assignment &>(d));
        return true;
    }
    else if (d.getEventType() == EventType::EXAM)
    {
        exams.push_back(static_cast<Exam &>(d));
        return true;
    }
    else
    {
        
        return addEventToCalendar(d);
    }
}

bool Day::addEventToCalendar(eventSkeleton &d)
{
    for (auto &e : events)
    {
        // Check if event d overlaps with event e
        if ((d.getStartTime() < e.getEndTime() && d.getEndTime() > e.getStartTime()) ||
            (e.getStartTime() < d.getEndTime() && e.getEndTime() > d.getStartTime()) || (d.getStartTime() == e.getStartTime() && d.getEndTime() == e.getEndTime()))
        {
            std::cout << "Event overlaps with another event" << std::endl;
            return false;
        }
    }
    // std::cout << "Start Time: " << d.getStartTime() << std::endl;
    // std::cout << "End Time: " << d.getEndTime() << std::endl;
    // std::cout << "Day: " << d.getDay() << std::endl;
    // std::cout << "Week: " << d.getWeek() << std::endl;
    // std::cout << "-----------------------" << std::endl;
    // If no overlap, add the event
    events.push_back(d);
    return true;
}

Week::Week(int weekNumber) : weekNumber(weekNumber)
{
    for (int i = 0; i < 7; i++)
    {
        days.push_back(Day(i));
    }
}

bool Week::addEvent(eventSkeleton &e)
{
    int day = e.getDay()-1;
    if (days[day].addEvent(e))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Calendar::Calendar()
{
    for (int i = 0; i < 52; i++)
    {
        weeks.push_back(Week(i));
    }
}
int incrementTime(int time)
{
    int hour = time / 100;
    int minute = time % 100;

    // Increment the hour
    hour += 1;

    // Handle overflow if the hour goes beyond 23 (24-hour format)
    if (hour == 24)
    {
        hour = 0;
    }

    // Return the new time in HHMM format
    return (hour * 100) + minute;
}

void Calendar::display()
{

    std::cout << "\n"+getColour("red",true) +""
                 "  ____      _                _            \n"
                 " / ___|__ _| | ___ _ __   __| | __ _ _ __ \n"
                 "| |   / _` | |/ _ \\ '_ \\ / _` |/ _` | '__|\n"
                 "| |__| (_| | |  __/ | | | (_| | (_| | |   \n"
                 " \\____\\__,_|_|\\___|_| |_|\\__,_|\\__,_|_|   \n"
                 "                                         \n"
                 "" +getColour("reset",true) +""
                 "=======================================================================================================================================================================================================";
    ;

    for (int i = 1; i < 53; i++)
    {
        displayWeek(i);
    }
}

void Calendar::displayWeek(int week)
{
    std::cout << getColour("red",false) + "\nWeek " << week << +""+ getColour("reset",false) +":" << std::endl;
    week = week -1;
    std::cout << "==================================================================================================================" << std::endl;

    // Print day headers
    std::cout << "|     Time    |    Monday   |    Tuesday  |   Wednesday  |   Thursday   |   Friday    |  Saturday   |    Sunday   |" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    // Initialize earliest and latest times
    int earliestTime = 2400;
    int latestTime = 0;

    // Find the earliest start time and latest end time across all days in the week
    for (int j = 0; j < 7; j++)
    {
        for (auto &e : weeks[week].days[j].events)
        {
            if (e.getStartTime() < earliestTime)
                earliestTime = e.getStartTime();
            if (e.getEndTime() > latestTime)
                latestTime = e.getEndTime();
        }
    }

    // If no events, skip to the next week
    if (earliestTime == 2400 && latestTime == 0)
    {
        std::cout << "|   No Events Scheduled for this Week                                                                             |" << std::endl;
        std::cout << "===================================================================================================================" << std::endl;
        return;
    }

    // Normalize times to the nearest hour
    earliestTime = (earliestTime / 100) * 100;
    latestTime = ((latestTime + 99) / 100) * 100; // Round up to the next hour

    // Loop through each time slot from earliest to latest time
    for (int currentTime = earliestTime; currentTime <= latestTime; currentTime = incrementTime(currentTime))
    {
        std::cout << "| " << std::setw(4) << std::setfill(' ') << currentTime << " - "
                  << std::setw(4) << std::setfill(' ') << incrementTime(currentTime) << " |";
        for (int j = 0; j < 7; j++)
        {
            std::string eventName = "";

            // Check for events that occupy the current time slot
            for (auto &e : weeks[week].days[j].events)
            {
                if (e.getStartTime() <= currentTime && e.getEndTime() > currentTime)
                {
                    eventName = e.getPaperCode();
                    if (eventName.length() > 10)
                    {
                        eventName = eventName.substr(0, 10) + "...";
                    }
                    break; // This currently assumes only one event per hour max. need to change this to allow for assignments to be added
                }
            }
            // Exams aswell and should be in red and yellow.
            //  Print the event name or empty space
            std::cout << " " << std::setw(11) << (eventName.empty() ? "" : eventName + " ") << " |";
        }
        std::cout << std::endl;
    }

    std::cout << "===================================================================================================================" << std::endl;
}

std::string Calendar::getColour(std::string colour, bool background)
{
    // Create a map to store color codes
    std::map<std::string, std::string> colors;

    // Insert foreground color codes into the map
    colors["reset"] = "\033[0m";
    colors["black"] = "\033[30m";
    colors["red"] = "\033[31m";
    colors["green"] = "\033[32m";
    colors["yellow"] = "\033[33m";
    colors["blue"] = "\033[34m";
    colors["magenta"] = "\033[35m";
    colors["cyan"] = "\033[36m";
    colors["white"] = "\033[37m";

    if (background)
    {
        colors["black"] = "\033[40m";
        colors["red"] = "\033[41m";
        colors["green"] = "\033[42m";
        colors["yellow"] = "\033[43m";
        colors["blue"] = "\033[44m";
        colors["magenta"] = "\033[45m";
        colors["cyan"] = "\033[46m";
        colors["white"] = "\033[47m";
    }

    if (colors.find(colour) != colors.end())
    {
        return colors[colour];
    }
    else
    {
        // If the color is not found, return reset code
        return colors["reset"];
    }
}

void Calendar::displaySemester(int semester)
{
    int startWeek = (semester - 1) * 16;
    int endWeek = startWeek + 16;
    for (int i = startWeek; i < endWeek; i++)
    {
        displayWeek(i);
    }
}

bool Calendar::addEvent(eventSkeleton &e)
{
    int week = e.getWeek()-1;
    if (weeks[week].addEvent(e))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Calendar::removeEvent(eventSkeleton &e)
{
    // Implement logic to remove event
    return true;
}

bool Calendar::editEvent(eventSkeleton &e)
{
    // Implement logic to edit event
    return true;
}

vector<paper> &Calendar::getPapers()
{
    return papers;
}

void Calendar::serialize(std::ofstream &outputFile) const
{
    // Serialize papers
    outputFile << papers.size() << std::endl; // Save the number of papers
    for (const auto &p : papers)
    {
        p.serialize(outputFile); // Call serialize function for each paper
    }

    // Serialize weeks
    outputFile << weeks.size() << std::endl; // Save the number of weeks (always 52)
    for (const auto &week : weeks)
    {
        outputFile << week.weekNumber << std::endl;  // Serialize week number
        outputFile << week.days.size() << std::endl; // Serialize number of days in the week
        for (const auto &day : week.days)
        {
            outputFile << day.dayNumber << std::endl; // Serialize day number

            // Serialize events, assignments, and exams
            outputFile << day.events.size() << std::endl;
            for (const auto &event : day.events)
            {
                event.serialize(outputFile); // Serialize each event
            }

            outputFile << day.assignments.size() << std::endl;
            for (const auto &assignment : day.assignments)
            {
                assignment.serialize(outputFile); // Serialize each assignment
            }

            outputFile << day.exams.size() << std::endl;
            for (const auto &exam : day.exams)
            {
                exam.serialize(outputFile); // Serialize each exam
            }
        }
    }
}

void Calendar::deserialize(std::ifstream &inputFile)
{
    this->papers.clear(); // Clear all papers
    this->weeks.clear();  // Clear all weeks

    for (int i = 0; i < 52; i++)
    {
        weeks.push_back(Week(i));
    }

    // Deserialize the papers
    size_t numPapers;

    inputFile >> numPapers;
    inputFile.ignore(); // Ignore the newline symbol

    for (size_t i = 0; i < numPapers; ++i)
    {
        paper p("default_paper", "default_code", 18);
        p.deserialize(inputFile);
        this->papers.push_back(p);
    }

    // Deserialize the weeks (is always 52 but this keeps it consistent)
    size_t numWeeks;

    inputFile >> numWeeks;
    inputFile.ignore(); // Ignrore the newline

    for (size_t i = 0; i < numWeeks; ++i)
    {
        int weekNumber;
        inputFile >> weekNumber; // Grab the week number
        inputFile.ignore();

        Week week(weekNumber); // Create a Week object with the weekNumber

        // Deserialize the days of the week
        size_t numDays; // Always 7!
        inputFile >> numDays;
        inputFile.ignore();

        for (size_t j = 0; j < numDays; ++j)
        {
            int dayNumber;
            inputFile >> dayNumber;
            inputFile.ignore();

            Day day(dayNumber);

            // Deserialize the events
            size_t numEvents; // Number of events in the day
            inputFile >> numEvents;
            inputFile.ignore();

            for (size_t k = 0; k < numEvents; ++k)
            {
                int eventTypeInteger;
                std::string paperCode, location;
                int day, week, startTime, endTime;

                inputFile >> eventTypeInteger;
                inputFile.ignore();

                std::getline(inputFile, paperCode);
                inputFile >> day >> week >> startTime >> endTime;
                inputFile.ignore();
                std::getline(inputFile, location);

                EventType eventType = static_cast<EventType>(eventTypeInteger);

                eventSkeleton event(eventType, paperCode, day, week, startTime, endTime, location);

                addNewEvent addNewEventManager(papers, this);

                this->addEvent(event);
            }
            // Deserialize assignments
            size_t numAssignments;
            inputFile >> numAssignments;
            inputFile.ignore(); // Ignore newline after the number of assignments

            for (size_t k = 0; k < numAssignments; ++k)
            {
                int eventTypeInteger;
                std::string paperCode, location;
                int day, week, startTime, endTime;

                inputFile >> eventTypeInteger;
                inputFile.ignore();

                std::getline(inputFile, paperCode);
                inputFile >> day >> week >> startTime >> endTime;
                inputFile.ignore();
                std::getline(inputFile, location);

                EventType eventType = static_cast<EventType>(eventTypeInteger);

                eventSkeleton event(eventType, paperCode, day, week, startTime, endTime, location);

                addNewEvent addNewEventManager(papers, this);

                this->addEvent(event);
            }

            // Deserialize exams
            size_t numExams;
            inputFile >> numExams;
            inputFile.ignore(); // Ignore newline after the number of exams

            for (size_t k = 0; k < numExams; ++k)
            {
                int eventTypeInteger;
                std::string paperCode, location;
                int day, week, startTime, endTime;

                inputFile >> eventTypeInteger;
                inputFile.ignore();

                std::getline(inputFile, paperCode);
                inputFile >> day >> week >> startTime >> endTime;
                inputFile.ignore();
                std::getline(inputFile, location);

                EventType eventType = static_cast<EventType>(eventTypeInteger);

                eventSkeleton event(eventType, paperCode, day, week, startTime, endTime, location);

                addNewEvent addNewEventManager(papers, this);

                this->addEvent(event);
            }

            week.days.push_back(day); // Add the day to the current week
        }

        weeks.push_back(week); // Add the week to the calendar
    }
}

// int main() {
//     Calendar calendar;
//     calendar.display();
//     // Additional logic for testing
//     return 0;
// }
bool Calendar::test()
{
    bool passed = true;
    Calendar testCalendar;
    // Base event
    Lecture newLecture = Lecture("COSC203", 3, 7, 900, 1000, "Lecture Theatre");
    testCalendar.addEvent(newLecture);

    // Event that overlap

    // Event that overlap
    Lab newLab = Lab("COSC203", 3, 7, 930, 1030, "Lecture 23");

    // Event that exactly overlap
    Lab newLab2 = Lab("COSC203", 3, 7, 900, 1000, "Lecture 23");

    // Event that does not overlap
    Lecture newLecut1 = Lecture("COSC203", 3, 7, 1000, 1030, "Lecture 28");

    if (!(testCalendar.addEvent(newLab) == false && testCalendar.addEvent(newLab2) == false))
    { // Test that events cannot overlap
        passed = false;
    }
    if (!(testCalendar.addEvent(newLecut1) == true))
    { // Test that events that do not overlap can be added
        passed = false;
    }

    std::cout << "-----------------------" << std::endl;
    std::cout << "\n\n\nAdding events passed\n\n\n"
              << std::endl;
    std::cout << "-----------------------\n-----------------------" << std::endl;

    Assignment newAssignment = Assignment("COSC203", 3, 7, 900, 0, "");
    if (!testCalendar.addEvent(newAssignment))
    {
        passed = false;
    }

    Exam newExam = Exam("COSC203", 3, 7, 930, 1230, "Mellor labs g10");
    if (!testCalendar.addEvent(newExam))
    {
        passed = false;
    }

    Tutorial newtutorial = Tutorial("COSC300", 5, 10, 930, 1030, "Saint Daves");
    if (!testCalendar.addEvent(newtutorial))
    {
        passed = false;
    }

    testCalendar.displayWeek(7);
    testCalendar.displaySemester(1);
    testCalendar.display();

    if (passed)
    {
        cout << ""+ getColour("green", true)+"Calender Test Passed"+ getColour("reset", false) << endl;
    }
    else
    {
        cout << "" +getColour("red", true)+"Calender Test Failed" << getColour("reset", false)<< endl;
    }
    return passed;
}
