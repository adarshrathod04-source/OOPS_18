#include <iostream>

// Base class
class Vehicle {
public:

    // Virtual function
    virtual void move() const {
        std::cout << "Vehicle is moving\n";
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Derived class
class Car : public Vehicle {
public:

    // Override base class function
    void move() const override {
        std::cout << "Car moves on roads\n";
    }
};

// Another derived class
class Boat : public Vehicle {
public:

    // Override base class function
    void move() const override {
        std::cout << "Boat moves on water\n";
    }
};

// Main function
int main() {

    Car car;
    Boat boat;

    car.move();
    boat.move();

    return 0;
}
