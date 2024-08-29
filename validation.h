#include <vector>
#include <string>

#pragma once

using namespace std;


class validation{

public:

    int getValidInteger(int min, int max, string &prompt);
    std::string getValidString(const std::string &prompt);
    int timeValidation(std::string &prompt, int minTime);


};