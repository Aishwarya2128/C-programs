
#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

class Fraction
{
private:
    int numerator, denominator;

    void simplify()
    {
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }

        int g = gcd(numerator, denominator);

        if (g != 0)
        {
            numerator /= g;
            denominator /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1)
    {
        numerator = n;
        denominator = d;

        if (denominator != 0)
            simplify();
        else
        {
            cout << "Error: Denominator cannot be zero." << endl;
            numerator = 0;
            denominator = 1;
        }
    }

    friend istream& operator>>(istream& in, Fraction& f)
    {
        in >> f.numerator >> f.denominator;

        if (f.denominator == 0)
        {
            in.setstate(ios::failbit);
            return in;
        }

        f.simplify();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f)
    {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main()
{
    Fraction f1, f2;

    cout << "Enter first fraction (numerator denominator): ";
    if (!(cin >> f1))
    {
        cout << "Invalid fraction input!" << endl;
        return 1;
    }

    cout << "Enter second fraction (numerator denominator): ";
    if (!(cin >> f2))
    {
        cout << "Invalid fraction input!" << endl;
        return 1;
    }

    cout << "\nFirst fraction = " << f1 << endl;
    cout << "Second fraction = " << f2 << endl;

    return 0;
}
