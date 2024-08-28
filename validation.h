#include <vector>
#include <string>

#pragma once

using namespace std;


class validation{

public:

    int getValidInteger();
    std::string getValidString(const std::string &prompt);
    int timeValidation(const std::string &prompt, int minTime);
    int dayValidation();
    int weekValidation();


};