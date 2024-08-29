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
    eventSkeleton testEvent = eventSkeleton(EventType::LECTURE, "COSC345", 1, 1, 930, 1000, "Mellor 3.1");
    validation v = validation();
    //Because it returns either we create a bool called passed then return based on it at end  or we can just do it like this
    if(calendar.test()&&testEvent.test()&&v.test()){
        std::cout << "Testing Passed" << std::endl;
    }else{
        std::cout << "Testing Failed" << std::endl;
        return 1;
    }
    

    

    
}