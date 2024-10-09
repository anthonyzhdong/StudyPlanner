#include <string>

class flashcard{
    private:
        std::string question;
        std::string answer;
        int difficulty; // 0-5, 0 being easiest, 5 being hardest
    public:
    flashcard(std::string& q,std::string& a);
    std::string getQuestion();
    std::string getAnswer();
    int getDifficulty();
    void setDifficulty(int diff);
};