#include <iostream>

// Abstract base class
class Shape {
public:

    // Pure virtual function
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

// Rectangle derived class
class Rectangle : public Shape {
private:
    double length;
    double width;

public:

    // Constructor
    Rectangle(double givenLength,
              double givenWidth)
        : length(givenLength),
          width(givenWidth) {}

    // Implement pure virtual function
    double area() const override {
        return length * width;
    }
};

// Circle derived class
class Circle : public Shape {
private:
    double radius;

public:

    // Constructor
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}

    // Implement area()
    double area() const override {
        return 3.141592653589793
               * radius * radius;
    }
};

// Main function
int main() {

    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.0);

    std::cout << "Rectangle Area: "
              << rectangle.area() << '\n';

    std::cout << "Circle Area: "
              << circle.area() << '\n';

    return 0;
}
