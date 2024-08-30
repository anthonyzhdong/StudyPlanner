#include "validation.h"
#include <string>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "addPaper.h"

using namespace std;


int validation::getValidInteger(int min, int max, string &prompt){
    string input;
    int number;

    while (true) {
        cout << prompt;
        getline(cin,input);

        // empty input
        if(input.empty()){
            cout << "Invalid input. Please try again.\n";
            continue;
        }
        try{
            number = stoi(input);

            if(number > max || number < min){
                cout << "Number is out of range. Please input a number between " << min << " and " << max << "\n";
                continue;
            }
            return number;
        }
        catch (const std::invalid_argument&) {
            cout << "Invalid input. Please enter a valid integer.\n";
        }
        catch (const std::out_of_range&) {
            cout << "Number is out of range. Please input a number between " << min << " and " << max << "\n";
        }
    }
}

string validation::getValidString(const std::string &prompt){
    string input;
    // filter
    string allowedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .";

    while (true) {
        cout << prompt;
        getline(cin,input);
        
        // empty input
        if(input.empty()){
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

int validation::timeValidation(std::string &prompt, int minTime = 0){

    string input;
    int hours, minutes, inputTime;

    while(true){
        cout << prompt;
        getline(cin,input);

        if(input.length() != 4){
            cout << "Invalid input. Please enter a 4 digit value e.g. 0930 for 9:30 AM\n";
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
            cout << "Invalid input. Please enter only digits\n";
            continue;
        }
        try{
            hours = stoi(input.substr(0,2));
            minutes = stoi(input.substr(2,2));

            if(hours < 0 || hours > 23 || minutes < 0 || minutes > 59){
                throw out_of_range("time out of range\n");
            }

            inputTime = hours * 100 + minutes;

            if(inputTime < minTime){
                cout << "Invalid time. Time must be later than start time of " << minTime << ".\n";
                continue;
            }
            return inputTime;

        }catch (const exception&){
            cout << "Invalid time. Please enter a valid 24-hour time\n";
            continue;
        }
    }

}

string validation::getValidPaperCode(vector<paper>& papers){
    string code;
    bool invalid = true;

    while(invalid){
        cout << "Enter code: ";
        getline(cin, code);
        for(auto &paper : papers){
            if(paper.getPaperCode() == code){
                return code;
            }
        }
        cout << "Invalid paper code. Please try again.\n";
    }
    return code;

}

bool validation::isValidPaper(const std::vector<paper> &papers, const std::string &paperCode)
{
    for (const auto &paper : papers)
    {
        if (paper.getPaperCode() == paperCode)
            return true;
    }
    return false;
}