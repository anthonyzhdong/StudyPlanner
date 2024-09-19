#include "StudySession.h"
#include <iostream>
#include <ctime>

StudySession::StudySession(string paperCode, int day, int week) : eventSkeleton(EventType::STUDY_SESSION, paperCode, day, week, 0, 0, "")
{
    this->startTime = 0;
    this->endTime = 0;
}

time_t StudySession::getStartTime() {
    return startTime;
}

time_t StudySession::getEndTime() {
    return endTime;
}

void StudySession::setStartTime(time_t startTime) {
    this->startTime = startTime;
}

void StudySession::setEndTime(time_t endTime) {
    this->endTime = endTime;
}

void StudySession::startSession() {
    time_t currentTime = time(nullptr); // Gets the current time
    setStartTime(currentTime);
    cout << "Study session started at " << ctime(&currentTime) << endl;;
}

void StudySession::endSession() {
    time_t currentTime = time(nullptr); // Gets the current time
    setEndTime(currentTime);
    cout << "Study session ended at " << ctime(&currentTime) << endl;
}

double StudySession::getDuration() {
    if (getStartTime() != 0 && getEndTime() != 0) {
        double duration = difftime(getEndTime(), getStartTime()); // Gets the difference between end and start time.
        return duration;
    } else if (getStartTime() != 0 && getEndTime() == 0) {
        // Session has not ended yet.
        double duration = difftime(time(nullptr), getStartTime()); // Gets the difference between now and start time.
        return duration;
    } else {
        // Session not started yet.
        cout << "The study session has not started yet." << endl;
        return 0.0;
    }
}

