#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <memory>

using namespace std;

class EventWrapper{
private:
    variant<Lecture, Tutorial, Lab> event;
    //assignment & exam

public: 
    // Constructor template to allow any event type to be wrapped
    template<typename T>
    EventWrapper(T&& e) : event(forward<T>(e)) {}

    // Get the type of the event as a string
    string getEventType() const {
        return visit([](const auto& e) -> std::string {
            return e.getEventType();
        }, event);
    }
    // Display the details of the wrapped event
    void displayDetails() const {
        visit([](const auto& e) {
            e.displayInfo();
        }, event);
    }
    // Check if the wrapped event is of a specific type
    template<typename T>
    bool is() const {
        return holds_alternative<T>(event);
    }

    // Get the wrapped event as a specific type
    template<typename T>
    const T& get() const {
        return get<T>(event);
    }




}