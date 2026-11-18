
#include <iostream>
#include <exception>
using namespace std;

class Overflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Overflow!";
    }
};

class Underflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Underflow!";
    }
};

class Stack {
    int a[3];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 2)
            throw Overflow();

        a[++top] = x;
        cout << x << " pushed\n";
    }

    void pop() {
        if (top == -1)
            throw Underflow();

        cout << "Popped: " << a[top--] << endl;
    }
};

int main() {
    Stack s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
    }
    catch (const Overflow &e) {
        cout << e.what() << endl;
    }

    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    }
    catch (const Underflow &e) {
        cout << e.what() << endl;
    }

    return 0;
}
