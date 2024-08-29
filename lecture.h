/**
 * @file lecture.h
 * @brief Defines the Lecture class, representing a lecture event in the calendar.
 */

#include <string>
#include "eventSkeleton.h"
#pragma once

/**
 * @class Lecture
 * @brief Represents a lecture event, inheriting from eventSkeleton.
 */
class Lecture : public eventSkeleton {
public:
    /**
     * @brief Constructor for the Lecture class.
     * @param paperCode Code of the paper associated with the lecture.
     * @param day Day of the lecture.
     * @param week Week of the lecture.
     * @param startTime Start time of the lecture.
     * @param endTime End time of the lecture.
     * @param location Location of the lecture.
     */
    Lecture(std::string paperCode, int day, int week, int startTime, int endTime, std::string location)
        : eventSkeleton(EventType::LECTURE, paperCode, day, week, startTime, endTime, location) {}


};
