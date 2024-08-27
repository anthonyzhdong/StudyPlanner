#pragma once
#include <string>
#include "eventSkeleton.h"

using namespace std;

class Exam : public eventSkeleton {
public:

    Exam(string paperCode, int day, int week, int startTime, int endTime, string location)
        : eventSkeleton(EventType::EXAM, paperCode, day, week, startTime, endTime, location) {}

};
