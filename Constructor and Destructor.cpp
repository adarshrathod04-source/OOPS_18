#include <iostream>

// Base class
class Base {
public:

    // Base constructor
    Base() {
        std::cout << "Base constructor\n";
    }

    // Base destructor
    ~Base() {
        std::cout << "Base destructor\n";
    }
};

// Derived class
class Derived : public Base {
public:

    // Derived constructor
    Derived() {
        std::cout << "Derived constructor\n";
    }

    // Derived destructor
    ~Derived() {
        std::cout << "Derived destructor\n";
    }
};

// Main function
int main() {

    // Create Derived object
    Derived object;

    return 0;
}
