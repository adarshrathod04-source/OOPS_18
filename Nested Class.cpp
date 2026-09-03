#include <iostream>
#include <string>
#include <utility>

// Outer class
class University {

public:

    // Nested class
    class Department {
    private:

        // Department name
        std::string name;

    public:

        // Constructor
        explicit Department(std::string departmentName)
            : name(std::move(departmentName)) {}

        // Display department
        void display() const {
            std::cout << "Department: "
                      << name << '\n';
        }
    };
};

// Main function
int main() {

    // Create object of nested class
    University::Department department(
        "Artificial Intelligence and Data Science"
    );

    // Display department
    department.display();

    return 0;
}
