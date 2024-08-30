#include <vector>
#include <string>
#include "paper.h"

#pragma once

using namespace std;

class validation
{

public:
    int getValidInteger(int min, int max, string &prompt);
    std::string getValidString(const std::string &prompt);
    int timeValidation(std::string &prompt, int minTime);
    string getValidPaperCode(vector<paper> &papers);
    bool isValidPaper(const std::vector<paper> &papers, const std::string &paperCode);
};