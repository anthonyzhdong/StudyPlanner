#pragma once

#include "Calendar.h"
#include "validation.h"
#include <iostream>
#include <iomanip>

class flashcardM {
private:
    Calendar* calendar;
    validation validate;


public:
    flashcardM(Calendar* cal);
    void displayPapers();
    void viewFlashcards();
    void addFlashcard();
    void practiceFlashcards();
    void deleteFlashcard();
   // void display();
};