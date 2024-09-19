#include "MenuItem.h"
#include <string>

MenuItem::MenuItem(const std::string &name, std::function<void()> action) : name(name), action(action) {}

std::string MenuItem::getName() const
{
    return name;
}

void MenuItem::execute() const
{
    action();
}

bool testVar = true;
void testAction() {
    testVar = false;
}

bool MenuItem::test() {
    bool passed = true;
    MenuItem testItem("Test item", testAction);
    // Check the name
    if (testItem.getName() != "Test item")
        passed = false;
    // Check if test executes
    testItem.execute();
    if (testVar)
        passed = false;

    return passed;

}

