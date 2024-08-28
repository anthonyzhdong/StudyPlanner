#pragma once

#include <vector>
#include "paper.h"

using namespace std;

class addPaper {
private:
    vector<paper>& papers;

public:
    // Constructor
    addPaper(vector<paper>& papers);

    // Method to add a paper
    void addPaperMenu();
    int getValidInteger();
};