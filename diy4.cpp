
#include <iostream>
using namespace std;

const double PI = 3.14159;

double volume(double side)
{
    return side * side * side;
}

double volume(double length, double breadth, double height)
{
    return length * breadth * height;
}

double volume(double radius, double height)
{
    return PI * radius * radius * height;
}

int main()
{
    double side, length, breadth, height, radius;

    cout << "Enter side of cube: ";
    cin >> side;
    cout << "Volume of cube = " << volume(side) << endl;

    cout << "\nEnter length, breadth and height of cuboid: ";
    cin >> length >> breadth >> height;
    cout << "Volume of cuboid = "
         << volume(length, breadth, height) << endl;

    cout << "\nEnter radius and height of cylinder: ";
    cin >> radius >> height;
    cout << "Volume of cylinder = "
         << volume(radius, height) << endl;

    return 0;
}
