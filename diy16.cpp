
#include <iostream>
using namespace std;

class Money
{
private:
    int rupees, paise;

public:
    Money(int r = 0, int p = 0)
    {
        int totalPaise = r * 100 + p;
        rupees = totalPaise / 100;
        paise = totalPaise % 100;
    }

    Money operator+(Money m)
    {
        int total1 = rupees * 100 + paise;
        int total2 = m.rupees * 100 + m.paise;

        int sum = total1 + total2;

        return Money(sum / 100, sum % 100);
    }

    Money operator-(Money m)
    {
        int total1 = rupees * 100 + paise;
        int total2 = m.rupees * 100 + m.paise;

        int diff = total1 - total2;

        return Money(diff / 100, diff % 100);
    }

    void display()
    {
        cout << "Rs. " << rupees << ".";
        if (paise < 10)
            cout << "0";
        cout << paise << endl;
    }
};

int main()
{
    int r1, p1, r2, p2;

    cout << "Enter first amount (rupees paise): ";
    cin >> r1 >> p1;

    cout << "Enter second amount (rupees paise): ";
    cin >> r2 >> p2;

    Money m1(r1, p1);
    Money m2(r2, p2);

    Money sum = m1 + m2;
    Money difference = m1 - m2;

    cout << "\nFirst amount: ";
    m1.display();

    cout << "Second amount: ";
    m2.display();

    cout << "Sum: ";
    sum.display();

    cout << "Difference (first - second): ";
    difference.display();

    return 0;
}
