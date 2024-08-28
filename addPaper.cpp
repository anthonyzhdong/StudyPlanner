#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "paper.h"
#include "addPaper.h"

using namespace std;

// constructor
addPaper::addPaper(vector<paper>& papers) : papers(papers) {}

void addPaper::addPaperMenu() {
    string paperName, paperCode;
    int paperPoints;

    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');  // Clear any leftover newline characters

    cout << "Enter the paper name: ";
    getline(cin, paperName);

    cout << "Enter the paper code: ";
    getline(cin, paperCode);

    //cout << "Enter the paper points: ";
    paperPoints = getValidInteger();

    paper newPaper(paperName, paperCode, paperPoints);
    papers.push_back(newPaper);

    //displays paper info
    papers.back().displayInfo();
    cout << "Paper added successfully!" << endl;
}

int addPaper::getValidInteger(){
    string input;
    long long number;
    char* endpoint;

    while (true) {
        cout << "Enter the papers points: ";
        getline(cin,input);

        // empty input
        if(input.empty()){
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        // converts string to long long
        number = strtoll(input.c_str(), &endpoint, 10);

        // checks if entire string was converted to long long
        if(*endpoint != '\0'){
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        // checks range
        if(number > INT_MAX || number <= 0){
            cout << "Number is out of range. Please try again.\n";
            continue;
        }

        // returns as int
        return static_cast<int>(number);
    }
}
