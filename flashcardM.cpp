#include "flashcardM.h"

flashcardM::flashcardM(Calendar* cal) : calendar(cal) {}

void flashcardM::displayPapers() {
    std::cout << "\n==================== Available Papers ====================\n\n";
    std::cout << "  " << std::left << std::setw(10) << "Code" << std::setw(50) << "Name" << "\n";
    std::cout << "  " << std::string(56, '-') << "\n";

    for (auto &paper : calendar->getPapers())
    {
        std::cout << "  " << std::left 
                << std::setw(10) << paper.getPaperCode() 
                << std::setw(50) << paper.getPaperName() << "\n";
    }

    std::cout << "\n" << std::string(58, '=') << "\n";
}

void flashcardM::viewFlashcards() {
    displayPapers();
    std::string paperCode = validate.getValidPaperCode(calendar->getPapers());

    for (auto &paper : calendar->getPapers()) {
        if (paper.getPaperCode() == paperCode) {
            if (paper.getFlashcards().empty()) {
                std::cout << "No flashcards to display." << std::endl;
            } else {
                paper.displayFlashcards();
            }
            break;
        }
    }
}

void flashcardM::addFlashcard() {
    displayPapers();
    std::string paperCode = validate.getValidPaperCode(calendar->getPapers());
    
    std::string question = validate.getValidString("Enter the question: ");
    std::string answer = validate.getValidString("Enter the answer: ");

    flashcard newCard(question, answer);

    for (auto &paper : calendar->getPapers()) {
        if (paper.getPaperCode() == paperCode) {
            paper.addFlashcard(newCard);
            std::cout << "Flashcard added to " << paper.getPaperName() << std::endl;
            break;
        }
    }
}

void flashcardM::practiceFlashcards() {
    displayPapers();
    std::string paperCode = validate.getValidPaperCode(calendar->getPapers());

    for (auto &paper : calendar->getPapers()) {
        if (paper.getPaperCode() == paperCode) {
            paper.practiceFlashcards();
            break;
        }
    }
}