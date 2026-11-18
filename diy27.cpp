
#include <iostream>
#include <exception>
using namespace std;

class MathError : public exception {
public:
    const char* what() const noexcept override {
        return "Math Error";
    }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "Division by Zero";
    }
};

int main() {
    int a = 10, b = 0;

    try {
        if (b == 0)
            throw DivideByZero();

        cout << a / b << endl;
    }
    catch (const DivideByZero &e) {
        cout << "Specific Error: " << e.what() << endl;
    }
    catch (const MathError &e) {
        cout << "General Error: " << e.what() << endl;
    }

    return 0;
}
