#include <vector>
#include <iostream>
#include "Calendar.h"
#include "Event.h"
#include "eventSkeleton.h"
#include "lecture.h"
#include "lab.h"
#include "assignment.h"
#include "exam.h"

using namespace std;

Day::Day(int dayNumber) : dayNumber(dayNumber) {
        // Constructor implementation
}

bool Day::addEvent(eventSkeleton& d) {
    for (auto& e : events) {
        // Check if event d overlaps with event e
        if ((d.getStartTime() < e.getEndTime() && d.getEndTime() > e.getStartTime()) ||
            (e.getStartTime() < d.getEndTime() && e.getEndTime() > d.getStartTime())
            || (d.getStartTime() == e.getStartTime() && d.getEndTime() == e.getEndTime())) {
            std::cout << "Event overlaps with another event" << std::endl;
            return false;
        }
    }
    std::cout << "Start Time: " << d.getStartTime() << std::endl;
    std::cout << "End Time: " << d.getEndTime() << std::endl;
    std::cout << "Day: " << d.getDay() << std::endl;
    std::cout << "Week: " << d.getWeek() << std::endl;
    std::cout << "-----------------------" << std::endl;
    // If no overlap, add the event
    events.push_back(d);
    return true;
}
//

Week::Week(int weekNumber) : weekNumber(weekNumber) {
    for(int i = 0; i < 7; i++) {
        days.push_back(Day(i));
    }
}

bool Week::addEvent(eventSkeleton &e) {
    int day = e.getDay();
    if(days[day].addEvent(e)){
        return true;
    }
    else{
        return false;   
    }
}

Calendar::Calendar() {
    for(int i = 0; i < 52; i++) {
        weeks.push_back(Week(i));
    }
}

void Calendar::display() {
    // Implement display logic
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 7; j++) {
            for (auto& e : weeks[i].days[j].events) {
                std::cout << "Start Time: " << e.getStartTime() << std::endl;
                std::cout << "End Time: " << e.getEndTime() << std::endl;
                std::cout << "Day: " << e.getEndTime() << std::endl;
                std::cout << "Week: " << e.getWeek() << std::endl;
                std::cout << "-----------------------" << std::endl;
            }
        }
    }
    std::cout << "-----------------------" << std::endl;
}

bool Calendar::addEvent(eventSkeleton& e) {
    int week = e.getWeek();
    if(weeks[week].addEvent(e)){
        return true;
    }
    else{
        return false;
    }
}

bool Calendar::removeEvent(eventSkeleton& e) {
    // Implement logic to remove event
    return true;
}

bool Calendar::editEvent(eventSkeleton& e) {
    // Implement logic to edit event
    return true;
}

// int main() {
//     Calendar calendar;
//     calendar.display();
//     // Additional logic for testing
//     return 0;
// }
bool Calendar::test(){
    bool passed = true;
    Calendar testCalendar;
    // Base event
    Lecture newLecture = Lecture("COSC203", 3, 7, 900, 1000, "Lecture Theatre");
    testCalendar.addEvent(newLecture);
    
    // Event that overlap 
    Lab newLab = Lab("COSC203", 3, 7, 930, 1030, "Lecture 23");

    // Event that exactly overlap 
    Lab newLab2 = Lab("COSC203", 3, 7, 900, 1000, "Lecture 23");

    // Event that does not overlap
    Lecture newLecut1= Lecture("COSC203", 3, 7, 1000, 1030, "Lecture 28");

    if(!(testCalendar.addEvent(newLab) == false && testCalendar.addEvent(newLab2)==false)){ // Test that events cannot overlap
        passed = false;
    }
    if(!(testCalendar.addEvent(newLecut1) == true)){ // Test that events that do not overlap can be added
        passed = false;
    }
    if(passed){
        cout << "Calender Test Passed" << endl;
    }else{
        cout << "Calender Test Failed" << endl;
    }
    return passed;
}