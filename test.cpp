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
#include <iostream>

#include <fstream>

int main(){

       // Redirect cin to read from the input file
    // const char* inputFile = std::getenv("INPUT_FILE");
    // if (inputFile) {
    //     std::ifstream in(inputFile);
    //     std::cin.rdbuf(in.rdbuf());
    // }

    Calendar calendar;
    eventSkeleton testEvent = eventSkeleton(EventType::LECTURE, "COSC345", 1, 1, 930, 1000, "Mellor 3.1");
    validation v = validation();
    paper testPaper = paper("name", "code",1);
    //Because it returns either we create a bool called passed then return based on it at end  or we can just do it like this
    if(calendar.test()&&testEvent.test()&&testPaper.test()){
        std::cout << "Testing Passed" << std::endl;
    }else{
        std::cout << "Testing Failed" << std::endl;
        return 1;
    }
    

    

    
}