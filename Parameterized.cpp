#include <iostream>
#include <string>
#include <utility>

// Base class
class Person {
protected:
    std::string name;

public:
    // Parameterized constructor
    explicit Person(std::string personName)
        : name(std::move(personName)) {}
};

// Derived class
class Student : public Person {
private:
    int rollNumber;

public:
    // Derived constructor
    Student(std::string studentName, int roll)
        // Call parameterized base constructor
        : Person(std::move(studentName)),
          rollNumber(roll) {}

    // Display student details
    void display() const {
        std::cout << "Name: "
                  << name << '\n';

        std::cout << "Roll Number: "
                  << rollNumber << '\n';
    }
};

// Main function
int main() {

    Student student("Kiran", 24);

    student.display();

    return 0;
}
