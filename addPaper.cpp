#include <iostream>
#include <string>
#include <vector>
#include "paper.h"
#include "addPaper.h"

using namespace std;

// Constructor
addPaper::addPaper(vector<paper>& papers) : papers(papers) {}

void addPaper::addPaperMenu() {
    string paperName, paperCode;
    int paperPoints;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear any leftover newline characters

    cout << "Enter the paper name: ";
    getline(cin, paperName);

    cout << "Enter the paper code: ";
    getline(cin, paperCode);

    cout << "Enter the paper points: ";
    cin >> paperPoints;

    paper newPaper(paperName, paperCode, paperPoints);
    papers.push_back(newPaper);
    //displays paper info
    papers.back().displayInfo();
    cout << "Paper added successfully!" << endl;
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include "paper.h"
// #include "addPaper.h"

// using namespace std;

// // add input validation
// class addPaper{

// private:
//     vector <paper>& papers;

// public:
//     //constructor
//     addPaper::addPaper(vector <paper>& papers){
//         this->papers = papers;
//     }


//     void addPaperMenu(){
//         string paperName, paperCode;
//         int paperPoints;

//         cout << "Enter the paper name: ";
//         getline(cin, paperName);

//         cout << "Enter the paper code: ";
//         getline(cin, paperCode);

        
//         cout << "Enter the paper points: ";
//         cin >> paperPoints;

//         paper newPaper = paper(paperName, paperCode, paperPoints);
//         papers.push_back(newPaper);

//         cout << "Paper added successfully!" << endl;


//     }

// };