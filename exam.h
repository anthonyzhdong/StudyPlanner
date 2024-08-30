/**
 * @file exam.h
 * @brief Defines the Exam class, representing an exam event in the calendar.
 */

#pragma once
#include <string>
#include "eventSkeleton.h"

/**
 * @class Exam
 * @brief Represents an exam event, inheriting from eventSkeleton.
 */
class Exam : public eventSkeleton {
public:
    /**
     * @brief Constructor for the Exam class.
     * @param paperCode Code of the paper associated with the exam.
     * @param day Day of the exam.
     * @param week Week of the exam.
     * @param startTime Start time of the exam.
     * @param endTime End time of the exam.
     * @param location Location of the exam.
     */
    Exam(std::string paperCode, int day, int week, int startTime, int endTime, std::string location)
        : eventSkeleton(EventType::EXAM, paperCode, day, week, startTime, endTime, location) {}

};
