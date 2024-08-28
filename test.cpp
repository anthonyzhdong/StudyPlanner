#include <iostream>
#include <vector>
#include <string>
#include "Calendar.h"
#include "paper.h"
#include "addPaper.h"
#include "eventSkeleton.h"
#include "addNewEvent.h"
#include "eventSkeleton.h"
#include <iostream>


int main(){
    Calendar calendar;
    if(calendar.test()){
        std::cout << "Testing Passed" << std::endl;
        return 0;
    }else{
        std::cout << "Testing Failed" << std::endl;
        return 1;
    }
    
    eventSkeleton testEvent = eventSkeleton(EventType::LECTURE, "COSC345", 1, 1, 930, 1000, "Mellor 3.1");
    if(testEvent.test()){
        std::cout << "Testing Passed" << std::endl;
        return 0;
    }else{
        std::cout << "Testing Failed" << std::endl;
        return 1;
    }
    

    
}