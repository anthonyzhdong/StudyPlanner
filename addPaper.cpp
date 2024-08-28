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

    paperName = getValidString("Enter the paper name: ");

    paperCode = getValidString("Enter the paper code: ");
    
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

string addPaper::getValidString(const string &prompt){
    string input;
    // filter
    string allowedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

    while (true) {
        cout << prompt;
        getline(cin,input);
        
        // empty input
        if(input.length() < 1){
            cout << "Input is too short\n";
            continue;
        }
        bool invalid = false;
        // checks each character to see if it's in filter
        for(char character : input){
            if(allowedCharacters.find(character) == string::npos){
                cout << "Invalid character: " << character << "\n";
                invalid = true;
                break;
            }
        }
        if(invalid){
            continue;
        }

        return input;
    }
}
