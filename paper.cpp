#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "paper.h"
#include "lecture.h"
#include "tutorial.h"
#include "lab.h"
#include "exam.h"
#include "assignment.h"
#include "eventSkeleton.h"


paper::paper(std::string paperName, std::string paperCode, int paperPoints)
    : paperName(paperName), paperCode(paperCode), paperPoints(paperPoints),
      events()
{
}
std::string paper::getPaperName() 
{
    return paperName;
}

std::string paper::getPaperCode() const
{
    return paperCode;
}

int paper::getPaperPoints() 
{
    return paperPoints;
}

// setter methods
void paper::setPaperName(std::string& paperName)
{
    this->paperName = paperName;
}

void paper::setPaperCode(std::string& paperCode)
{
    this->paperCode = paperCode;
}

void paper::setPaperPoints(int paperPoints)
{
    this->paperPoints = paperPoints;
}

void paper::addEvent(eventSkeleton& event)
{
    events.push_back(event);
}

void paper::displayInfo()  {
    cout << "Paper: " << paperName << " (" << paperCode << ")" << endl;
    cout << "Points: " << paperPoints << endl;
    cout << "Events:" << endl;
    for ( auto& event : events) {
        cout << "Event on day " << event.getDay() << " of week " << event.getWeek() << endl;
    }
}

void paper::serialize(std::ofstream &outputFile) const {
    outputFile << this->paperName << std::endl;
    outputFile << this->paperCode << std::endl;
    outputFile << this->paperPoints << std::endl;
}

void paper::deserialize(std::ifstream &inputFile) {
    std::getline(inputFile, this->paperName);
    std::getline(inputFile, this->paperCode);
    inputFile >> this->paperPoints;
    inputFile.ignore(); // Ignore newline
}

void paper::addFlashcard(flashcard& card) {
    flashcards.push_back(card);
}

vector<flashcard> paper::getFlashcards() {
    return flashcards;
}

void paper::displayFlashcards(){
    for(auto& card : flashcards){
        std::cout << "\nQuestion: " << card.getQuestion() << std::endl;
        std::cout << "Answer: " << card.getAnswer() << std::endl;
        std::cout << "Difficulty: " << card.getDifficulty() << std::endl;
    }
}

void paper::practiceFlashcards(){
    if(flashcards.empty()){
        std::cout << "No flashcards to practice." << std::endl;
        return;
    }
    
    // shuffles the deck randomly
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(flashcards.begin(), flashcards.end(), g);
    int count = 1;
    for(auto& card: flashcards){
        std::cout << "Question: " << card.getQuestion() << std::endl;
        std::cout << "Press enter to reveal the answer." << std::endl;
        std::cin.ignore();
       // std::cin.get();

        std::cout << "Answer: " << card.getAnswer() << std::endl;
        std::cout << "Rate the difficulty of this card (0 - easy <-> 5 - hard): ";
        int rating;
        std::cin >> rating;
        card.setDifficulty(rating);
        
        if(count == flashcards.size()){
            std::cout << "End of flashcards." << std::endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the buffer
            break;
        }else{
            std::cout << "Next card? (y/n): ";
            char next;
            std::cin >> next;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the buffer
            if(next != 'y' && next != 'Y'){
                break;
            }
        }
        count++;
    }


}

bool paper::test(){
    bool passed = true;

    paper testPaper = paper("Software Engineering", "COSC345", 15);
    // change values
    string newName = "Advanced Software Engineering";
    testPaper.setPaperName(newName);
    string newCode = "COSC400";
    testPaper.setPaperCode(newCode);
    int newPoints = 18;
    testPaper.setPaperPoints(newPoints);
    // create events
    eventSkeleton testEvent1 = eventSkeleton(EventType::LECTURE, "COSC400", 1, 1, 930, 1000, "Mellor 3.1");
    eventSkeleton testEvent2 = eventSkeleton(EventType::TUTORIAL, "COSC400", 1, 2, 1400, 1500, "Mellor 3.2");
    eventSkeleton testEvent3 = eventSkeleton(EventType::LAB, "COSC400", 2, 1, 930, 1200, "Mellor 3.3");
    // add events
    testPaper.addEvent(testEvent1);
    testPaper.addEvent(testEvent2);
    testPaper.addEvent(testEvent3);
    // test that values are set correctly
    if (testPaper.getPaperName() != newName){
        cout << "Error: Paper name not set correctly." << endl;
        passed = false;
    }
    if (testPaper.getPaperCode() != newCode){
        cout << "Error: Paper code not set correctly." << endl;
        passed = false;
    }
    if (testPaper.getPaperPoints() != newPoints){
        cout << "Error: Paper points not set correctly." << endl;
        passed = false;
    }
    // test that events are added correctly
    if (testPaper.events.size() != 3){
        cout << "Error: Events not added correctly." << endl;
        passed = false;
    }
    if (passed){
        cout << "Paper test passed." << endl;
    }else{
        cout << "Paper test failed." << endl;
    }

    return passed;


}
