#include "eventSkeleton.h"
using namespace std;
#include <string>

/**
eventSkeleton is the parent class
lecture, tutorial, lab, assignment, exam, study session should have their own properties
addNewEvent asks user for input
create the object
put into a vector <eventSkeleton> events
also push onto the paper object

events is used in calendar
 */

// constructor
eventSkeleton::eventSkeleton(string paperCode, int day, int week)
    : paperCode(paperCode), day(day), week(week) {
}

// getter methods
string eventSkeleton::getPaperCode(){
    return paperCode;
}
int eventSkeleton::getDay(){
    return day;
}

int eventSkeleton::getWeek(){
    return week;
}

// setter methods

void eventSkeleton::setPaperCode(string& paperCode){
    this->paperCode = paperCode;
}
void eventSkeleton::setDay(int day){
    this->day = day;
}
void eventSkeleton::setWeek(int week){
    this->week = week;
}


