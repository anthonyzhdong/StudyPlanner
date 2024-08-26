#pragma once
#include <functional>
#include <string>

class MenuItem {
private:
    std::string name;
    std::function<void()> action;
public:
    MenuItem(const std::string& name, std::function<void()> action);

    std::string getName() const;

    // Run the menu function
    void execute() const;
};