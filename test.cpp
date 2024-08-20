#include "Calendar.h"
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