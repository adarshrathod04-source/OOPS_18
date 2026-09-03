#include <iostream>
#include <string>
#include <utility>

// Abstract base class
class Employee {
protected:

    // Employee ID
    int employeeId;

    // Employee name
    std::string name;

public:

    // Constructor
    Employee(int id, std::string employeeName)
        : employeeId(id),
          name(std::move(employeeName)) {}

    // Pure virtual function
    virtual double calculateSalary() const = 0;

    // Display basic details
    void displayBasicDetails() const {

        std::cout << "Employee ID: "
                  << employeeId << '\n';

        std::cout << "Name: "
                  << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

// Permanent employee class
class PermanentEmployee : public Employee {
private:

    // Basic salary
    double basicSalary;

    // Additional allowance
    double allowance;

public:

    // Constructor
    PermanentEmployee(
        int id,
        std::string employeeName,
        double basic,
        double extra)

        : Employee(id, std::move(employeeName)),
          basicSalary(basic),
          allowance(extra) {}

    // Calculate permanent employee salary
    double calculateSalary() const override {
        return basicSalary + allowance;
    }
};

// Contract employee class
class ContractEmployee : public Employee {
private:

    // Salary per hour
    double hourlyRate;

    // Total hours worked
    int hoursWorked;

public:

    // Constructor
    ContractEmployee(
        int id,
        std::string employeeName,
        double rate,
        int hours)

        : Employee(id, std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Calculate contract salary
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Function to display employee payslip
void displayPaySlip(const Employee& employee) {

    // Display employee ID and name
    employee.displayBasicDetails();

    // Calculate and display salary
    std::cout << "Salary: "
              << employee.calculateSalary()
              << "\n\n";
}

// Main function
int main() {

    // Create permanent employee
    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0
    );

    // Create contract employee
    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80
    );

    // Display permanent employee payslip
    displayPaySlip(permanentEmployee);

    // Display contract employee payslip
    displayPaySlip(contractEmployee);

    return 0;
}
