
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) {
        name = n;
        id = i;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Manager : public Employee {
    int teamSize;

public:
    Manager(string n, int i, int t) : Employee(n, i) {
        teamSize = t;
    }

    void show() {
        cout << "\nManager Details\n";
        display();
        cout << "Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;

public:
    Engineer(string n, int i, string s) : Employee(n, i) {
        skill = s;
    }

    void show() {
        cout << "\nEngineer Details\n";
        display();
        cout << "Skill: " << skill << endl;
    }
};

int main() {
    Manager m("Aishwarya", 101, 10);
    Engineer e("Rahul", 102, "C++");

    m.show();
    e.show();

    return 0;
}
