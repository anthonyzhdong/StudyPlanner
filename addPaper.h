#pragma once

#include <vector>
#include "paper.h"
#include "validation.h"

using namespace std;

class addPaper {
private:
    vector<paper>& papers;
    validation validate;

public:
    // Constructor
    addPaper(vector<paper>& papers);

    // Method to add a paper
    void addPaperMenu();
    //int getValidInteger();
    //string getValidString(const string &prompt);
};