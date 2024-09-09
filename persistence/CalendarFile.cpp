#include "CalendarFile.h"
#include <fstream>
#include <iostream>

void CalendarFile::saveToFile(const Calendar& calendar, const std::string& fileName) {
    std::ofstream outputFile(fileName, std::ios::binary | std::ios::trunc);

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open file for saving: " << fileName << std::endl;
        return;
    }

    // Save papers
    

     
};