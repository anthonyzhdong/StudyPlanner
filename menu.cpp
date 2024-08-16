#include <iostream>
#include <vector>
#include <string>
using namespace std;
// g++ -o menu menu.cpp
// ./menu


void displayMenu()
{
    cout << "\n===== Paper Management System =====\n";
    // cout << "Type a command and press enter.\n";
    // cout << "Display item(s): display <papers|lectures|labs|tutorials|assignments>\n";
    // cout << "Add an item: add <paper|lecture|lab|tutorial|assignment>\n"; // After typing this, prompt the user to add details.
    // cout << "Remove an item: remove <paper|lecture|lab|tutorial|assignment>"; // After typing this, prompt the user to add details of what to delete.
    cout << "1. Display papers\n";
    cout << "2. Display calendar\n";
    cout << "3. Add event\n";
    int number;
    // have to figure out how to switch between states
    while(true){
        if(cin >> number){
            if(number == 1){
                //display papers
                break;
            }else if(number ==2){
                //display calendar
                break;
            }else if(number ==3){
                //add event
                break;
            }
        }else{
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
    }
    cout << "input: " << number << endl;

}

int main()
{
    displayMenu();

    return 0;
}
