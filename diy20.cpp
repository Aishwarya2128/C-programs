
#include <iostream>
using namespace std;

class Shape {
protected:
    int length;

public:
    Shape(int l) {
        length = l;
        cout << "Shape Constructor\n";
    }
};

class Polygon : public Shape {
protected:
    int width;

public:
    Polygon(int l, int w) : Shape(l) {
        width = w;
        cout << "Polygon Constructor\n";
    }
};

class Rectangle : public Polygon {
public:
    Rectangle(int l, int w) : Polygon(l, w) {
        cout << "Rectangle Constructor\n";
    }

    void area() {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << length * width << endl;
    }
};

int main() {
    Rectangle r(10, 5);
    r.area();

    return 0;
}
