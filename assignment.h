/**
 * @file assignment.h
 * @brief Defines the Assignment class, representing an assignment event in the calendar.
 */
#include <string>
#include "eventSkeleton.h"
#pragma once

using namespace std;

/**
 * @class Assignment
 * @brief Represents an assignment event, inheriting from eventSkeleton.
 */
class Assignment : public eventSkeleton {
public:
    /**
     * @brief Constructor for the Assignment class.
     * @param paperCode Code of the paper associated with the assignment.
     * @param day Due day of the assignment.
     * @param week Due week of the assignment.
     * @param startTime Start time for working on the assignment (if applicable).
     * @param endTime End time or due time of the assignment.
     * @param location Location for submitting the assignment (if applicable).
     */
    Assignment(string paperCode, int day, int week, int startTime, int endTime, string location)
        : eventSkeleton(EventType::ASSIGNMENT, paperCode, day, week, startTime, endTime, location) {}

};
