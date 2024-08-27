#include <iostream>
#include <vector>
#include <string>
#include "Calendar.h"
#include "paper.h"
#include "addPaper.h"
#include "eventSkeleton.h"
#include "addNewEvent.h"
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
    
}