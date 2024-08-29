/**
 * @file addPaper.h
 * @brief Defines the addPaper class for adding new papers to the system
 */

#pragma once

#include <vector>
#include "paper.h"
#include "validation.h"

/**
 * @class addPaper
 * @brief Manages the addition of new papers to the system
 */
class addPaper {
private:
    std::vector<paper>& papers;
    validation validate;

public:
        /**
     * @brief Construct a new addPaper object
     * 
     * @param papers Reference to the vector of papers in the system
     */
    addPaper(std::vector<paper>& papers);

    /**
     * @brief Displays a menu and handles the process of adding a new paper
     */
    void addPaperMenu();
};