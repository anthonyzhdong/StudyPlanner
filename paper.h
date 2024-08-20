#pragma once

#include <string>
#include <vector>
#include "lecture.h"
#include "tutorial.h"
#include "lab.h"

class Paper {
private:
    std::string paperName;
    std::string paperCode;
    int paperPoints;
    std::vector<lecture> lectures;
    std::vector<tutorial> tutorials;
    std::vector<lab> labs;

public:
    // Constructor
    Paper(std::string paperName, std::string paperCode, int paperPoints);

    // Getters
    std::string getPaperName() const;
    std::string getPaperCode() const;
    int getPaperPoints() const;

    // Setters
    void setPaperName(const std::string& paperName);
    void setPaperCode(const std::string& paperCode);
    void setPaperPoints(int paperPoints);

    // Methods to add classes
    void addLecture(const lecture& lecture);
    void addTutorial(const tutorial& tutorial);
    void addLab(const lab& lab);

    // Method to display paper information
    void displayInfo() const;
};
