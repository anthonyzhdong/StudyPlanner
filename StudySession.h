/**
 * @file StudySession.h
 * @brief Defines the StudySession class, representing a study session event in the calendar.
 */

#pragma once
#include "eventSkeleton.h"
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

/**
 * @class StudySession
 * @brief Represents a study session event, inheriting from eventSkeleton.
 */
class StudySession : public eventSkeleton
{
private:
    time_t startTime; /**< Start time of the study session */
    time_t endTime; /**< End time of the study session */

public:

    /**
     * @brief Constructor for the StudySession class.
     * @param paperCode Code of the paper associated with the study session.
     * @param day Day of the study session.
     * @param week Week of the study session.
     */
    StudySession(string paperCode, int day, int week);

    /**
     * @brief Get the start time of the study session.
     * @return The start time of the study session as a time_t value.
     */
    time_t getStartTime();

    /**
     * @brief Get the end time of the study session.
     * @return The end time of the study session as a time_t value.
     */
    time_t getEndTime();

    /**
     * @brief Start the study session.
     * @param startTime Start time of the study session.
     */
    void setStartTime(time_t startTime);
    /**
     * @brief End the study session.
     * @param endTime End time of the study session.
     */
    void setEndTime(time_t endTime);

    /**
     * @brief Get the duration of the study session.
     * @return The duration of the study session in seconds.
     */
    double getDuration(); 

    /**
     * @brief Start the study session.
     */
    void startSession();

    /**
     * @brief End the study session.
     */
    void endSession();


    /**
     * @brief Tests the functionality of the StudySession class.
     * @return true if all tests pass, false otherwise.
     */
    static bool test();
};