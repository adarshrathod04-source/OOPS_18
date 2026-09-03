#include <iostream>
#include <string>
#include <utility>

// Base class
class Vehicle {
protected:

    // Vehicle registration number
    std::string registrationNumber;

    // Daily rental rate
    double ratePerDay;

public:

    // Constructor
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)),
          ratePerDay(rate) {}

    // Calculate rent
    virtual double calculateRent(int days) const {
        return ratePerDay * days;
    }

    // Display vehicle details
    virtual void display() const {
        std::cout << "Registration: "
                  << registrationNumber << '\n';

        std::cout << "Rate per day: "
                  << ratePerDay << '\n';
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Car derived class
class Car : public Vehicle {
private:

    // Number of doors
    int numberOfDoors;

public:

    // Car constructor
    Car(std::string registration,
        double rate,
        int doors)

        : Vehicle(std::move(registration), rate),
          numberOfDoors(doors) {}

    // Override display()
    void display() const override {

        // Display common vehicle details
        Vehicle::display();

        // Display car-specific detail
        std::cout << "Doors: "
                  << numberOfDoors << '\n';
    }
};

// Bike derived class
class Bike : public Vehicle {
private:

    // Engine capacity
    int engineCapacity;

public:

    // Bike constructor
    Bike(std::string registration,
         double rate,
         int capacity)

        : Vehicle(std::move(registration), rate),
          engineCapacity(capacity) {}

    // Override rent calculation
    double calculateRent(int days) const override {

        // Bike gets 10% discount
        return ratePerDay * days * 0.9;
    }

    // Override display()
    void display() const override {

        // Display common details
        Vehicle::display();

        // Display bike-specific detail
        std::cout << "Engine Capacity: "
                  << engineCapacity
                  << " cc\n";
    }
};

// Main function
int main() {

    // Create Car object
    Car car("MH12AB1234", 2000.0, 5);

    // Create Bike object
    Bike bike("MH12CD5678", 800.0, 150);

    // Display car information
    std::cout << "Car Details\n";
    car.display();

    // Calculate car rent for 3 days
    std::cout << "Rent for 3 days: "
              << car.calculateRent(3)
              << "\n\n";

    // Display bike information
    std::cout << "Bike Details\n";
    bike.display();

    // Calculate bike rent for 3 days
    std::cout << "Rent for 3 days: "
              << bike.calculateRent(3)
              << '\n';

    return 0;
}
