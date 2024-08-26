#include "MenuItem.h"

MenuItem::MenuItem(const std::string &name, std::function<void()> action) : name(name), action(action) {}

std::string MenuItem::getName() const {
    return name;
}

void MenuItem::execute() const {
    action();
}