#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>
#include "paper.h"

class Utilities {
    public:
    static bool isValidPaper(const std::vector<paper>& papers, const std::string& paperCode);
};

#endif