
#include <iostream>
using namespace std;

inline int minVal(int a, int b)
{
    return (a < b) ? a : b;
}

inline int minVal(int a, int b, int c)
{
    return minVal(minVal(a, b), c);
}

int main()
{
    int a, b, c;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Smaller of two numbers = "
         << minVal(a, b) << endl;

    cout << "\nEnter three integers: ";
    cin >> a >> b >> c;

    cout << "Smallest of three numbers = "
         << minVal(a, b, c) << endl;

    return 0;
}
