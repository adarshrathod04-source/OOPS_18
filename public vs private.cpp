#include <iostream>      // For cout

// Base class
class Base {
public:
    // Public function
    void show() const {
        std::cout << "Base public function\n";
    }
};

// Public inheritance
class PublicDerived : public Base {
    // Base public members remain public
};

// Private inheritance
class PrivateDerived : private Base {
public:
    // Public function of derived class
    void callBaseShow() const {
        // Can access inherited show() internally
        show();
    }
};

// Main function
int main() {

    // Object of publicly derived class
    PublicDerived publicObject;

    // show() is accessible
    publicObject.show();

    // Object of privately derived class
    PrivateDerived privateObject;

    // Call through derived-class function
    privateObject.callBaseShow();

    // This would produce an error:
    // privateObject.show();

    return 0;
}
