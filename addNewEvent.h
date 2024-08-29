#include <string>
#include <vector>
#include "paper.h"
#include "Calendar.h"
#include "validation.h"
#pragma once

using namespace std;

class addNewEvent{
private:
    vector<paper>& papers;
    Calendar* calendar;
    validation validate;
    string getValidPaperCode();
public:
    addNewEvent(vector<paper>& papers, Calendar* calendar);
    
    void addNewEventMenu();

    vector<eventSkeleton> getEvents();
};