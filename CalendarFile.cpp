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
            cout << "Closed calendar file" << endl;
        }
    };

    
    void loadFromFile(Calendar &calendar, const std::string &fileName) {
        
    }
}