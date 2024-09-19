/**
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

/** 
* @mainpage
* 
* This is the mainpage for the documentation of the Calendar application.
* 
* The Calendar application is designed to help students manage their academic schedules by allowing them to add, view, and edit events, assignments, and exams.
* 
* The application is built using C++ and includes classes such as Calendar, Day, Week, Paper, eventSkeleton, Assignment, Exam, and Validation.
* 
* The Calendar class represents the entire calendar, which contains multiple weeks. Each week contains multiple days, and each day can have events, assignments, and exams.
* 
* The paper class represents a paper (course) in the academic context. It contains information such as the paper name, code, points, and associated events.
* 
* The eventSkeleton class is an abstract class that represents a generic event. It is inherited by the assignment and exam classes, which provide specific implementations for assignments and exams.
* 
* The validation class provides methods for validating user input, such as getting a valid integer, string, or time input.
* 
* The Calendar application also includes a menu system that allows users to interact with the application by selecting options to view the calendar, add events, add papers, start and end study sessions, and exit the application.
* 
* The addNewEvent class manages the process of adding new events to the calendar by presenting a menu to the user to select a paper and the type of event they wish to add.
* 
* The application is designed to be user-friendly and intuitive, providing students with a convenient way to keep track of their academic commitments and deadlines.
*/