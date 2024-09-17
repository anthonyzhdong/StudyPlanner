/**
 * @file CalendarFile.h
 * @brief Header file for the CalendarFile class
 */

#pragma once
#include "Calendar.h"
#include <string>

/**
 * @namespace CalendarFile
 * @brief Contains static functions to save and load a calendar from a file.
 */
namespace CalendarFile
{
    /**
     * @brief Function to save a calendar object to a file
     * @param calendar The calendar address to be saved
     * @param fileName The name of the file to save the calendar to. Don't use a file extension!
     */
    void saveToFile(Calendar &calendar, const std::string &fileName);

    /**
     * @brief Function to load a calendar object from a file
     * @param calendar The calendar address to be loaded into
     * @param fileName The name of the file to load the calendar from. Don't include the file extension!
     */
    void loadFromFile(Calendar &calendar, const std::string &fileName);
};