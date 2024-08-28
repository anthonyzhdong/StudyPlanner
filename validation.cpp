#include "validation.h"
#include <string>
#include <iostream>
#include <limits>
#include "addPaper.h"

using namespace std;


int validation::getValidInteger(int min, int max){
    string input;
    long long number;
    char* endpoint;

    while (true) {
        cout << "Enter the papers points: ";
        getline(cin,input);

        // empty input
        if(input.empty()){
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        // converts string to long long
        number = strtoll(input.c_str(), &endpoint, 10);

        // checks if entire string was converted to long long
        if(*endpoint != '\0'){
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        // checks range
        if(number > max || number <= min){
            cout << "Number is out of range. Please try again.\n";
            continue;
        }

        // returns as int
        return static_cast<int>(number);
    }
}

string validation::getValidString(const std::string &prompt){
    string input;
    // filter
    string allowedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

    while (true) {
        cout << prompt;
        getline(cin,input);
        
        // empty input
        if(input.length() < 1){
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

int validation::timeValidation(const std::string &prompt, int minTime = 0){
    return 0;
}
int validation::dayValidation(){
    return 0;
}
int validation::weekValidation(){
    return 0;
}