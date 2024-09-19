#include <iostream>
#include <vector>
#include <string>
#include "Calendar.h"
#include "paper.h"
#include "addPaper.h"
#include "eventSkeleton.h"
#include "addNewEvent.h"
#include "eventSkeleton.h"
#include "validation.h"
#include "CalendarFile.h"
#include <iostream>

#include <fstream>
#include <sstream>

bool testGetValidInteger() {
    validation v;
    std::string prompt = "Enter a number between 1 and 100: ";
    int result = v.getValidInteger(1, 40, prompt);
    std::cout << "getValidInteger result: " << result << std::endl;
    return (result >= 1 && result <= 100);
}


int main(){


    bool allTestsPassed = true;
    // Test getValidInteger with input redirection
    std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); // save old buf
    std::cin.rdbuf(in.rdbuf()); // redirect std::cin to input.txt

    bool getValidIntegerPassed = testGetValidInteger();
    allTestsPassed &= getValidIntegerPassed;
    std::cout << "getValidInteger test " << (getValidIntegerPassed ? "passed" : "failed") << std::endl;

    // Restore cin to its original buf
    std::cin.rdbuf(cinbuf);

    // Existing tests
    Calendar calendar;
    eventSkeleton testEvent = eventSkeleton(EventType::LECTURE, "COSC345", 1, 1, 930, 1000, "Mellor 3.1");
    paper testPaper = paper("name", "code", 1);

    bool calendarTestPassed = calendar.test();
    bool eventTestPassed = testEvent.test();
    bool paperTestPassed = testPaper.test();
    bool calendarFileTestPassed = CalendarFile::test();

    allTestsPassed &= calendarTestPassed && eventTestPassed && paperTestPassed && calendarFileTestPassed;

    if (allTestsPassed) {
        std::cout << "Allthe  tests passed" << std::endl;
    } else {
        std::cout << "Somethe tests failed" << std::endl;
        return 1;
    }

    return 0;

    // Calendar calendar;
    // eventSkeleton testEvent = eventSkeleton(EventType::LECTURE, "COSC345", 1, 1, 930, 1000, "Mellor 3.1");
    // validation v = validation();
    // paper testPaper = paper("name", "code",1);
    // //Because it returns either we create a bool called passed then return based on it at end  or we can just do it like this
    // if(calendar.test()&&testEvent.test()&&testPaper.test()){
    //     std::cout << "Testing Passed" << std::endl;
    // }else{
    //     std::cout << "Testing Failed" << std::endl;
    //     return 1;
    // }
    

    

    
}