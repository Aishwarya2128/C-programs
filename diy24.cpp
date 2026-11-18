
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor\n";
    }

    virtual ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
    int *ptr;

public:
    Derived() {
        ptr = new int[5];
        cout << "Derived Constructor\n";
    }

    ~Derived() {
        delete[] ptr;
        cout << "Derived Destructor\n";
    }
};

int main() {
    Base *b = new Derived();

    delete b;

    return 0;
}
