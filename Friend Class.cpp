#include <iostream>

// Account class
class Account {
private:

    // Private data
    double balance;

    // Auditor is allowed to access private members
    friend class Auditor;

public:

    // Constructor
    explicit Account(double initialBalance)
        : balance(initialBalance) {}
};

// Auditor class
class Auditor {
public:

    // Inspect account
    void inspect(const Account& account) const {

        // Access Account's private balance
        std::cout << "Account Balance: "
                  << account.balance << '\n';
    }
};

// Main function
int main() {

    Account account(5000.0);

    Auditor auditor;

    auditor.inspect(account);

    return 0;
}
