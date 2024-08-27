#include <vector>
#include <iostream>
#include "Calendar.h"
#include "Event.h"
#include "eventSkeleton.h"
#include "lecture.h"
#include "lab.h"
#include "assignment.h"
#include "exam.h"
#include <iomanip> 
#include <sstream>

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
int incrementTime(int time) {
    int hour = time / 100;  
    int minute = time % 100;  

    // Increment the hour
    hour += 1;

    // Handle overflow if the hour goes beyond 23 (24-hour format)
    if (hour == 24) {
        hour = 0;
    }

    // Return the new time in HHMM format
    return (hour * 100) + minute;
}

void Calendar::display() {
    for (int i = 0; i < 52; i++) {
        std::cout << "\nWeek " << i + 1 << ":" << std::endl;
        std::cout << "==================================================================================================================" << std::endl;
        
        // Print day headers
        std::cout << "|     Time    |    Monday   |    Tuesday  |   Wednesday  |   Thursday   |   Friday    |  Saturday   |    Sunday   |" << std::endl;
        std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
        
        // Initialize earliest and latest times
        int earliestTime = 2400;
        int latestTime = 0;
        
        // Find the earliest start time and latest end time across all days in the week
        for (int j = 0; j < 7; j++) {
            for ( auto& e : weeks[i].days[j].events) {
                if (e.getStartTime() < earliestTime) earliestTime = e.getStartTime();
                if (e.getEndTime() > latestTime) latestTime = e.getEndTime();
            }
        }
        
        // If no events, skip to the next week
        if (earliestTime == 2400 && latestTime == 0) {
            std::cout << "|   No Events Scheduled for this Week                                                                             |" << std::endl;
            std::cout << "===================================================================================================================" << std::endl;
            continue;
        }
        
        // Normalize times to the nearest hour
        earliestTime = (earliestTime / 100) * 100;
        latestTime = ((latestTime + 99) / 100) * 100; // Round up to the next hour
        
        // Loop through each time slot from earliest to latest time
        for (int currentTime = earliestTime; currentTime <= latestTime; currentTime = incrementTime(currentTime)) {
            std::cout << "| " << std::setw(4) << std::setfill(' ') << currentTime << " - "
                      << std::setw(4) << std::setfill(' ') << incrementTime(currentTime) << " |";
            for (int j = 0; j < 7; j++) {
                std::string eventName = "";
                
                // Check for events that occupy the current time slot
                for ( auto& e : weeks[i].days[j].events) {
                    if (e.getStartTime() <= currentTime && e.getEndTime() > currentTime) {
                        eventName = e.getPaperCode();
                        if (eventName.length() > 10) {
                            eventName = eventName.substr(0, 10) + "...";
                        }
                        break; // This currently assumes only one event per hour max.
                    }
                }
                
                // Print the event name or empty space
                std::cout << " " << std::setw(11) << (eventName.empty() ? "" : eventName+" ") << " |";
            }
            std::cout << std::endl;
        }
        
        std::cout << "===================================================================================================================" << std::endl;
    }
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

    std::cout << "-----------------------" << std::endl;
    std::cout << "\n\n\nAdding events passed\n\n\n" << std::endl;
    std::cout << "-----------------------\n-----------------------" << std::endl;
    testCalendar.display();


    if(passed){
        cout << "Calender Test Passed" << endl;
    }else{
        cout << "Calender Test Failed" << endl;
    }
    return passed;
}