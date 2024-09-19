#include "CalendarFile.h"
#include "Calendar.h"
#include <fstream>
#include <iostream>

namespace CalendarFile
{
    bool saveToFile(Calendar &calendar, const std::string &fileName)
    {

        std::ofstream outputFile(fileName);

        if (!outputFile.is_open())
        {
            std::cerr << "Failed to open file for saving: " << fileName << std::endl;
            return false;
        }
        if (outputFile.is_open())
        {

            // Save calendar

            calendar.serialize(outputFile);
            cout << "Saved calendar to file " << fileName << endl;

            outputFile.close();
        }
        return true;
    };

    bool loadFromFile(Calendar &calendar, const std::string &fileName)
    {
        std::ifstream inputFile(fileName);

        if (!inputFile.is_open())
        {
            std::cerr << "Failed to open file for loading: " << fileName << std::endl;
            return false;
        }

        if (inputFile.is_open())
        {
            calendar.deserialize(inputFile);
            cout << "Loaded calendar from file " << fileName << endl;

            inputFile.close();
        }
        return true;
    }

    bool test()
    {
        bool passed = true;
        Calendar testCalendar;

        eventSkeleton testEvent = eventSkeleton(EventType::LECTURE, "COSC345", 1, 1, 930, 1000, "Mellor 3.1");
        paper testPaper = paper("name", "code", 1);

        eventSkeleton testEvent2 = eventSkeleton(EventType::ASSIGNMENT, "COSC345", 1, 1, 930, 1000, "Mellor 3.1");
        testCalendar.getPapers().push_back(testPaper);
        testCalendar.addEvent(testEvent);
        testCalendar.addEvent(testEvent2);
        Calendar testLoadCalendar;

        if (!CalendarFile::saveToFile(testCalendar, "testcal.txt"))
        {
            passed = false;
        }
        if (!CalendarFile::loadFromFile(testLoadCalendar, "testcal.txt"))
        {
            passed = false;
        }
        return passed;
    }
}