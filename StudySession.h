#include "eventSkeleton.h"
#include <string>
#include <chrono>
#pragma #once
using namespace std;
using namespace chrono;

class StudySession : public eventSkeleton
{
private:
    time_t startTime;
    time_t endTime;

public:
    StudySession(string paperCode, int day, int week);

    time_t getStartTime();
    time_t getEndTime();

    void setStartTime(time_t startTime);
    void setEndTime(time_t endTime);

    double getDuration(); // Returns the duration of the study session in seconds
    void startSession();
    void endSession();

};