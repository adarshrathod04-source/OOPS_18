#include <iostream>

// First base class
class Academic {
protected:
    int academicMarks;

public:
    // Constructor
    explicit Academic(int marks)
        : academicMarks(marks) {}

    // Display academic marks
    void showAcademic() const {
        std::cout << "Academic Marks: "
                  << academicMarks << '\n';
    }
};

// Second base class
class Sports {
protected:
    int sportsMarks;

public:
    // Constructor
    explicit Sports(int marks)
        : sportsMarks(marks) {}

    // Display sports marks
    void showSports() const {
        std::cout << "Sports Marks: "
                  << sportsMarks << '\n';
    }
};

// Student inherits from two classes
class Student : public Academic, public Sports {
public:
    // Constructor
    Student(int academic, int sports)
        : Academic(academic),
          Sports(sports) {}

    // Calculate total marks
    void showTotal() const {
        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks
                  << '\n';
    }
};

// Main function
int main() {

    Student student(80, 15);

    student.showAcademic();
    student.showSports();
    student.showTotal();

    return 0;
}
