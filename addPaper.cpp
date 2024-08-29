#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "paper.h"
#include "addPaper.h"


using namespace std;

// constructor
addPaper::addPaper(vector<paper>& papers) : papers(papers) {}


/**
 * @brief Creates the add paper menu for the user to create a paper.
 *
 * This function prompts the user to enter a papers name, code, points and then displays the papers information
 * and displays the papers information that they added aswell as promting them that the paper has been successfully added.
 *
 * @param none
 * @return none
 */
void addPaper::addPaperMenu() {
    string paperName, paperCode;
    int paperPoints;

    //cin.ignore(numeric_limits<std::streamsize>::max(), '\n');  // Clear any leftover newline characters

    paperName = validate.getValidString("Enter the paper name: ");

    paperCode = validate.getValidString("Enter the paper code: ");
    
    string pointsPrompt =  "Enter the paper points: ";
    paperPoints = validate.getValidInteger(1, 1000, pointsPrompt);

    paper newPaper(paperName, paperCode, paperPoints);
    papers.push_back(newPaper);

    //displays paper info
    papers.back().displayInfo();
    cout << "Paper added successfully!" << endl;
}