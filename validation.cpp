#include "validation.h"
#include <string>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>
#include "addPaper.h"



int validation::getValidInteger(int min, int max, std::string &prompt){
    std::string input;
    int number;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin,input);

        // empty input
        if(input.empty()){
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        bool valid = true;
        for (size_t i = 0; i < input.length(); ++i) {
            if (!std::isdigit(input[i])) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            continue;
        }
        try{
            number = std::stoi(input);

            if(number > max || number < min){
                std::cout << "Number is out of range. Please input a number between " << min << " and " << max << "\n";
                continue;
            }
            return number;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid integer.\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Number is out of range. Please input a number between " << min << " and " << max << "\n";
        }
    }
}

std::string validation::getValidString(const std::string &prompt){
    std::string input;
    // filter
    std::string allowedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .";

    while (true) {
        std::cout << prompt;
        std::getline(cin,input);
        
        // empty input
        if(input.empty()){
            std::cout << "Input is too short\n";
            continue;
        }
        bool invalid = false;
        // checks each character to see if it's in filter
        for(char character : input){
            if(allowedCharacters.find(character) == std::string::npos){
                std::cout << "Invalid character: " << character << "\n";
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

int validation::timeValidation(std::string &prompt, int minTime = 0){

    std::string input;
    int hours, minutes, inputTime;

    while(true){
        std::cout << prompt;
        std::getline(cin,input);

        if(input.length() != 4){
            std::cout << "Invalid input. Please enter a 4 digit value e.g. 0930 for 9:30 AM\n";
            continue;
        }
        bool allDigits = true;
        for(char character : input){
            if (character < '0' || character > '9'){
                allDigits = false;
                break;
            }
        }
        if(!allDigits){
            std::cout << "Invalid input. Please enter only digits\n";
            continue;
        }
        try{
            hours = std::stoi(input.substr(0,2));
            minutes = std::stoi(input.substr(2,2));

            if(hours < 0 || hours > 23 || minutes < 0 || minutes > 59){
                throw out_of_range("time out of range\n");
            }

            inputTime = hours * 100 + minutes;

            if(inputTime < minTime){
                std::cout << "Invalid time. Time must be later than start time of " << minTime << ".\n";
                continue;
            }
            return inputTime;

        }catch (const exception&){
            std::cout << "Invalid time. Please enter a valid 24-hour time\n";
            continue;
        }
    }

}

std::string validation::getValidPaperCode(std::vector<paper>& papers){
    std::string code;
    bool invalid = true;

    while(invalid){
        std::cout << "Enter code: ";
        std::getline(cin, code);
        for(auto &paper : papers){
            if(paper.getPaperCode() == code){
                return code;
            }
        }
        std::cout << "Invalid paper code. Please try again.\n";
    }
    return code;
}

bool validation::test(){
    bool passed = true;
    
    // Test getValidInteger
    cout << "TESTING";
    string p = "\nEnter a number between 1 and 10: \n";
    int num = getValidInteger(1, 10, p);
    if (num < 1 || num > 10) {
        std::cout << "getValidInteger test failed\n";
        passed = false;
    }
    return passed;
}