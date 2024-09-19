#include "CalendarFile.h"
#include <fstream>
#include <iostream>

namespace CalendarFile
{
    void saveToFile(Calendar &calendar, const std::string &fileName)
    {

        std::ofstream outputFile(fileName);

        if (!outputFile.is_open())
        {
            std::cerr << "Failed to open file for saving: " << fileName << std::endl;
            return;
        }
        if (outputFile.is_open())
        {

            // Save calendar

            calendar.serialize(outputFile);
            cout << "Saved calendar" << endl;

            outputFile.close();
        }
    };

    void loadFromFile(Calendar &calendar, const std::string &fileName)
    {
        std::ifstream inputFile(fileName);

        if (!inputFile.is_open())
        {
            std::cerr << "Failed to open file for loading: " << fileName << std::endl;
            return;
        }

        if (inputFile.is_open())
        {
            calendar.deserialize(inputFile);
            cout << "Loaded calendar" << endl;

            inputFile.close();
        }
    }
}