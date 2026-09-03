#include <iostream>
#include <string>
#include <utility>

// Base class
class Person {
protected:
    std::string name;

public:

    // Constructor
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Display name
    void displayName() const {
        std::cout << "Name: "
                  << name << '\n';
    }
};

// Student virtually inherits Person
class Student : virtual public Person {
public:

    Student()
        : Person("Unknown") {}
};

// Employee virtually inherits Person
class Employee : virtual public Person {
public:

    Employee()
        : Person("Unknown") {}
};

// TeachingAssistant inherits Student and Employee
class TeachingAssistant
    : public Student, public Employee {

public:

    // Constructor
    explicit TeachingAssistant(
        std::string assistantName)

        // Initialize the single Person virtual base
        : Person(std::move(assistantName)),
          Student(),
          Employee() {}
};

// Main function
int main() {

    TeachingAssistant assistant("Riya");

    assistant.displayName();

    return 0;
}
