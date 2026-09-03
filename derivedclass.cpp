 #include <iostream>      // Provides input/output functions like cout
#include <string>        // Provides the string data type
#include <utility>       // Provides std::move

// Base class
class Person {
protected:
    std::string name;    // Protected variable storing person's name

public:
    // Constructor of Person
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Function to display the name
    void displayName() const {
        std::cout << "Name: " << name << '\n';
    }
};

// Student inherits publicly from Person
class Student : public Person {
private:
    int rollNumber;      // Private variable storing roll number

public:
    // Constructor of Student
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), // Call Person constructor
          rollNumber(roll) {}             // Initialize roll number

    // Function to display student information
    void displayStudent() const {
        displayName();    // Call inherited function
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Main function
int main() {
    // Create Student object
    Student student("Amit", 101);

    // Display student details
    student.displayStudent();

    return 0;             // End program
}
