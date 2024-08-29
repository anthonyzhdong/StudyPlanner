#include <string>
#include <vector>
#include "paper.h"
#include "Calendar.h"
#include "validation.h"
#pragma once

using namespace std;

class addNewEvent{
private:
    vector<paper>& papers;
    Calendar* calendar;
    validation validate;
    string getValidPaperCode();
public:

    addNewEvent(vector<paper>& papers, Calendar* calendar);
    /**
 * @brief Displays the menu for adding a new event and handles user input.
 *
 * This function presents a menu to the user to select a paper and the type of event they wish to add.
 * Based on the event type, it prompts for the appropriate details (e.g., time, day, week) and adds the event to the Calendar.
 *
 * @param none
 * @return none
 */
    void addNewEventMenu();

    vector<eventSkeleton> getEvents();
};