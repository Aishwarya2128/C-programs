
#include <iostream>
using namespace std;

class Base {
public:
    void normal() {
        cout << "Base::normal (early binding)" << endl;
    }

    virtual void special() {
        cout << "Base::special" << endl;
    }
};

class Derived : public Base {
public:
    void normal() {
        cout << "Derived::normal" << endl;
    }

    void special() override {
        cout << "Derived::special (late binding)" << endl;
    }
};

int main() {
    Derived d;
    Base *p = &d;

    p->normal();
    p->special();

    return 0;
}
