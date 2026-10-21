
#include <iostream>
using namespace std;

int power(int base, int exp = 2)
{
    int result = 1;

    for (int i = 1; i <= exp; i++)
    {
        result = result * base;
    }

    return result;
}

int main()
{
    int base, exp;

    cout << "Enter the base: ";
    cin >> base;

    cout << "Power with default exponent = "
         << power(base) << endl;

    cout << "\nEnter the base and exponent: ";
    cin >> base >> exp;

    cout << "Power = " << power(base, exp) << endl;

    return 0;
}
