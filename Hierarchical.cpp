#include <iostream>
#include <string>
#include <utility>

// Base class
class Vehicle {
protected:
    std::string registrationNumber;

public:
    // Constructor
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {}

    // Common function
    void start() const {
        std::cout << "Vehicle "
                  << registrationNumber
                  << " started\n";
    }
};

// Car inherits Vehicle
class Car : public Vehicle {
public:
    // Car constructor
    explicit Car(std::string registration)
        : Vehicle(std::move(registration)) {}

    // Car-specific function
    void openBoot() const {
        std::cout << "Car boot opened\n";
    }
};

// Bike also inherits Vehicle
class Bike : public Vehicle {
public:
    // Bike constructor
    explicit Bike(std::string registration)
        : Vehicle(std::move(registration)) {}

    // Bike-specific function
    void helmetReminder() const {
        std::cout << "Please wear a helmet\n";
    }
};

// Main function
int main() {

    Car car("MH12AB1234");
    Bike bike("MH12CD5678");

    car.start();
    car.openBoot();

    bike.start();
    bike.helmetReminder();

    return 0;
}
