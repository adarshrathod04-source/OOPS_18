#include <iostream>
#include <string>
#include <utility>

// First/base level
class Person {
protected:
    std::string name;

public:
    // Person constructor
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Display person name
    void showPerson() const {
        std::cout << "Name: " << name << '\n';
    }
};

// Employee inherits Person
class Employee : public Person {
protected:
    int employeeId;

public:
    // Employee constructor
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)),
          employeeId(id) {}

    // Display employee ID
    void showEmployee() const {
        std::cout << "Employee ID: " << employeeId << '\n';
    }
};

// Manager inherits Employee
class Manager : public Employee {
private:
    int teamSize;

public:
    // Manager constructor
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id),
          teamSize(size) {}

    // Display complete manager information
    void showManager() const {
        showPerson();
        showEmployee();
        std::cout << "Team Size: " << teamSize << '\n';
    }
};

// Main function
int main() {
    Manager manager("Ravi", 501, 8);

    manager.showManager();

    return 0;
}
