#include "flashcard.h"

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