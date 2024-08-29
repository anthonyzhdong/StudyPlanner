/**
 * @file lab.h
 * @brief Defines the Lab class, representing a lab event in the calendar.
 */

#include <string>
#include "eventSkeleton.h"
#pragma once

using namespace std;

/**
 * @class Lab
 * @brief Represents a lab event, inheriting from eventSkeleton.
 */
class Lab : public eventSkeleton {
public:
    /**
     * @brief Constructor for the Lab class.
     * @param paperCode Code of the paper associated with the lab.
     * @param day Day of the lab.
     * @param week Week of the lab.
     * @param startTime Start time of the lab.
     * @param endTime End time of the lab.
     * @param location Location of the lab.
     */
    Lab(string paperCode, int day, int week, int startTime, int endTime, string location)
        : eventSkeleton(EventType::LAB, paperCode, day, week, startTime, endTime, location) {}

};
