
#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor called\n";
    }

    void display() {
        cout << "Smart Pointer Example\n";
    }

    ~MyClass() {
        cout << "Destructor called\n";
    }
};

int main() {
    unique_ptr<MyClass> ptr = make_unique<MyClass>();

    ptr->display();

    return 0;
}
