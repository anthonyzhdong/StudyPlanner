#include "flashcard.h"
#include <iostream>

flashcard::flashcard(std::string q,std::string a) 
    : question(q), answer(a), difficulty(3) {} // Start at medium difficulty

std::string flashcard::getQuestion(){ 
    return question; 
}

std::string flashcard::getAnswer(){ 
    return answer; 
}

int flashcard::getDifficulty(){ 
    return difficulty; 
}

void flashcard::setDifficulty(int diff) { 
    difficulty = diff; 
}

bool flashcard::test(){
    flashcard testFlashcard = flashcard("What is the capital of New Zealand?", "Wellington");
    testFlashcard.setDifficulty(5);
    if(testFlashcard.getQuestion() == "What is the capital of New Zealand?" && testFlashcard.getAnswer() == "Wellington" && testFlashcard.getDifficulty() == 5){
        std::cout << "Flashcard test passed" << std::endl;
        return true;
    }else{
        std::cout << "Flashcard test failed" << std::endl;
        return false;
    }
}