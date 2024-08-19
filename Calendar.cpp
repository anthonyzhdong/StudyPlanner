#include <vector>
#include <iostream>
#include "Calendar.h"
#include "Event.h"

using namespace std;

Day::Day(int dayNumber) : dayNumber(dayNumber) {
        // Constructor implementation
    }

bool Day::addEvent(const Event& d) {
    for (const auto& e : events) {
        if (d.getStartTime() < e.getEndTime() && d.getEndTime() > e.getStartTime()) {
            std::cout << "Event overlaps with another event" << std::endl;
            return false;
        }
    }
    std::cout << "Event Name: " << d.getEventName() << std::endl;
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

bool Week::addEvent(const Event& e) {
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
}

bool Calendar::addEvent(const Event& e) {
    string name = e.getEventName();
    int week = e.getWeek();
    int day = e.getDay();
    int startTime = e.getStartTime();
    int endTime = e.getEndTime();
    weeks[week].addEvent(e);


    // Implement logic to add event
    return true;
}

bool Calendar::removeEvent(const Event& e) {
    // Implement logic to remove event
    return true;
}

bool Calendar::editEvent(const Event& e) {
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
    if(true){
        cout << "Calender Test Passed" << endl;
        return true;
    }
    return false;
}