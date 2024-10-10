#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "paper.h"
#include "addPaper.h"


addPaper::addPaper(std::vector<paper>& papers) : papers(papers) {}

void addPaper::addPaperMenu() {
    std::string paperName, paperCode;
    int paperPoints;
    std::cout << "\n═══════════════════════ Paper Details ═══════════════════════\n\n";
    paperName = validate.getValidString("Enter the paper name: ");
    paperCode = validate.getValidString("Enter the paper code: ");  
    std::string pointsPrompt =  "Enter the paper points: ";
    paperPoints = validate.getValidInteger(1, 1000, pointsPrompt);

    paper newPaper(paperName, paperCode, paperPoints);
    papers.push_back(newPaper);
    
    //displays paper info
    // could add like a paper overview header
    papers.back().displayInfo();
    cout << "\nPaper added successfully!\n" << endl;
}