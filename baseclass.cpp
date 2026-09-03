#include <iostream>      // For cout
#include <string>        // For string
#include <utility>       // For move

// Base class
class Employee {
protected:
    std::string name;    // Protected member

public:
    // Constructor
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName)) {}
};

// Derived class
class Developer : public Employee {
private:
    std::string language; // Programming language

public:
    // Constructor
    Developer(std::string employeeName,
              std::string programmingLanguage)
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage)) {}

    // Display information
    void display() const {
        // Access protected member inherited from Employee
        std::cout << "Developer: " << name << '\n';

        // Access private member of Developer
        std::cout << "Language: " << language << '\n';
    }
};

// Main function
int main() {
    Developer developer("Neha", "C++");

    developer.display();

    return 0;
}
