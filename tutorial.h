/**
 * @file tutorial.h
 * @brief Defines the Tutorial class, representing a tutorial event in the calendar.
 */

#include <string>
#include "eventSkeleton.h"
#pragma once

/**
 * @class Tutorial
 * @brief Represents a tutorial event, inheriting from eventSkeleton.
 */
class Tutorial : public eventSkeleton {
public:
    /**
     * @brief Constructor for the Tutorial class.
     * @param paperCode Code of the paper associated with the tutorial.
     * @param day Day of the tutorial.
     * @param week Week of the tutorial.
     * @param startTime Start time of the tutorial.
     * @param endTime End time of the tutorial.
     * @param location Location of the tutorial.
     */
    Tutorial(std::string paperCode, int day, int week, int startTime, int endTime, std::string location)
        : eventSkeleton(EventType::TUTORIAL, paperCode, day, week, startTime, endTime, location) {}

};
