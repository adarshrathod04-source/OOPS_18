#include <iostream>

// First base class
class Academic {
public:
    void display() const {
        std::cout << "Academic information\n";
    }
};

// Second base class
class Sports {
public:
    void display() const {
        std::cout << "Sports information\n";
    }
};

// Student inherits both classes
class Student : public Academic, public Sports {
public:
    void displayAll() const {

        // Specify Academic's display()
        Academic::display();

        // Specify Sports' display()
        Sports::display();
    }
};

// Main function
int main() {

    Student student;

    // Call Academic version
    student.Academic::display();

    // Call Sports version
    student.Sports::display();

    // Call both through displayAll()
    student.displayAll();

    return 0;
}
