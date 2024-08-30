/**
 * \mainpage
 * @file addNewEvent.h
 * @brief Header file for the addNewEvent class, which handles adding new events to the calendar.
 */

#include <string>
#include <vector>
#include "paper.h"
#include "Calendar.h"
#include "validation.h"
#pragma once

/**
 * @class addNewEvent
 * @brief Manages the process of adding new events to the calendar.
 */
class addNewEvent{
private:
    std::vector<paper>& papers;
    Calendar* calendar;
    validation validate;
    /**
     * @brief Gets a valid paper code from the user.
     * @return A valid paper code as a string.
     */
    std::string getValidPaperCode();
public:
    
    /**
     * @brief Constructor for the addNewEvent class.
     * @param papers Reference to the vector of papers.
     * @param calendar Pointer to the Calendar object.
     */
    addNewEvent(std::vector<paper>& papers, Calendar* calendar);

    /**
     * @brief Displays the menu for adding a new event and handles user input.
     *
     * This function presents a menu to the user to select a paper and the type of event they wish to add.
     * Based on the event type, it prompts for the appropriate details (e.g., time, day, week) and adds the event to the Calendar.
     */
    void addNewEventMenu();
    
    /**
     * @brief Gets the list of events.
     * @return A vector of eventSkeleton objects representing the events.
     */
    std::vector<eventSkeleton> getEvents();
};