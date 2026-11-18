
#include <iostream>
using namespace std;

class Account {
public:
    virtual double calculateInterest() = 0;
    virtual ~Account() {}
};

class Savings : public Account {
    double balance;

public:
    Savings(double b) {
        balance = b;
    }

    double calculateInterest() override {
        return balance * 0.05;
    }
};

class Current : public Account {
    double balance;

public:
    Current(double b) {
        balance = b;
    }

    double calculateInterest() override {
        return balance * 0.03;
    }
};

int main() {
    Account *a[2];

    a[0] = new Savings(10000);
    a[1] = new Current(10000);

    cout << "Savings Interest: "
         << a[0]->calculateInterest() << endl;

    cout << "Current Interest: "
         << a[1]->calculateInterest() << endl;

    delete a[0];
    delete a[1];

    return 0;
}
