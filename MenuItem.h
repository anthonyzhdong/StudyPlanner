/**
 * @file MenuItem.h
 * @brief Header file for the MenuItem class
 */

#pragma once
#include <functional>
#include <string>

/**
 * @class MenuItem
 * @brief Represents an item in a menu
 */
class MenuItem
{
private:
    std::string name;
    std::function<void()> action;

public:

    /**
     * @brief Construct a new MenuItem object
     * @param name The name of the menu item
     * @param action The function to be executed when this item is selected
     */
    MenuItem(const std::string &name, std::function<void()> action);

    /**
     * @brief Get the name of the menu item
     * @return std::string The name of the menu item
     */
    std::string getName() const;

    /**
     * @brief Execute the action associated with this menu item
     */
    void execute() const;

    
    /**
     * @brief Test the menuitem  functionality
     * @return True if passes, false if not
     */
    bool test();
};