
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
public:
    Student(string n) : Person(n) {}
};

class Employee : virtual public Person {
public:
    Employee(string n) : Person(n) {}
};

class TA : public Student, public Employee {
public:
    TA(string n) : Person(n), Student(n), Employee(n) {}

    void show() {
        cout << "Teaching Assistant Details\n";
        display();
    }
};

int main() {
    TA t("Aishwarya");
    t.show();

    return 0;
}
