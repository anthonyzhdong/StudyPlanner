/**
 * \mainpage
 * @file validation.h
 * @brief Defines the validation class which provides input validation methods.
 */

#include <vector>
#include <string>
#include "paper.h"

#pragma once


/**
 * @class validation
 * @brief Provides methods for validating user input.
 */
class validation{

public:

    
    /**
     * @brief Get a valid integer input within a specified range.
     * @param min Minimum allowed value.
     * @param max Maximum allowed value.
     * @param prompt Prompt message for the user.
     * @return A valid integer within the specified range.
     */
    int getValidInteger(int min, int max, std::string &prompt);

    /**
     * @brief Get a valid string input.
     * @param prompt Prompt message for the user.
     * @return A valid string input.
     */
    std::string getValidString(const std::string &prompt);

    /**
     * @brief Validate time input in 24-hour format.
     * @param prompt Prompt message for the user.
     * @param minTime Minimum allowed time (default is 0).
     * @return A valid time in 24-hour format.
     */
    int timeValidation(std::string &prompt, int minTime);

    /**
     * @brief Get a valid paper code from a list of papers.
     * @param papers Vector of paper objects to check against.
     * @return A valid paper code.
     */
    string getValidPaperCode(vector<paper>& papers);

    /**
     * @brief Tests the functionality of the validation class.
     * @return true if all tests pass, false otherwise.
     */
    bool test();

};