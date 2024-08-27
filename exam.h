#pragma once
#include <string>
#include "eventSkeleton.h"

using namespace std;

class exam : public eventSkeleton {
public:

    exam(string paperCode, int day, int week, int startTime, int endTime, string location)
        : eventSkeleton(EventType::EXAM, paperCode, day, week, startTime, endTime, location) {}

};
