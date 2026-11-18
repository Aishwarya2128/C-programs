
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;

public:
    Circle(double radius) {
        r = radius;
    }

    void area() override {
        cout << "Circle Area: " << 3.14159 * r * r << endl;
    }
};

class Square : public Shape {
    double s;

public:
    Square(double side) {
        s = side;
    }

    void area() override {
        cout << "Square Area: " << s * s << endl;
    }
};

class Triangle : public Shape {
    double b, h;

public:
    Triangle(double base, double height) {
        b = base;
        h = height;
    }

    void area() override {
        cout << "Triangle Area: " << 0.5 * b * h << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    int n;
    cout << "Enter number of shapes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;

        cout << "\nEnter shape (circle/square/triangle): ";
        cin >> name;

        if (name == "circle") {
            double r;
            cout << "Enter radius: ";
            cin >> r;

            shapes.push_back(make_unique<Circle>(r));
        }
        else if (name == "square") {
            double s;
            cout << "Enter side: ";
            cin >> s;

            shapes.push_back(make_unique<Square>(s));
        }
        else if (name == "triangle") {
            double b, h;
            cout << "Enter base and height: ";
            cin >> b >> h;

            shapes.push_back(make_unique<Triangle>(b, h));
        }
        else {
            cout << "Invalid shape\n";
        }
    }

    cout << "\nShape Areas:\n";

    for (auto &s : shapes) {
        s->area();
    }

    return 0;
}
