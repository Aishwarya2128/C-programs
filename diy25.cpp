
#include <iostream>
#include <exception>
using namespace std;

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient Balance!";
    }
};

class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount > balance)
            throw InsufficientFunds();

        balance -= amount;
        cout << "Withdrawal Successful\n";
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main() {
    BankAccount b(5000);

    try {
        double amount;
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        b.withdraw(amount);
    }
    catch (const InsufficientFunds &e) {
        cout << e.what() << endl;
    }

    return 0;
}
