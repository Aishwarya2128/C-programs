
#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray
{
private:
    int *arr;
    int size;

public:
    SafeArray(int n)
    {
        size = n;
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    int& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Array index out of range!");
        }

        return arr[index];
    }

    ~SafeArray()
    {
        delete[] arr;
    }
};

int main()
{
    int n, index, value;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    SafeArray a(n);

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter index to access: ";
    cin >> index;

    try
    {
        cout << "Element at index " << index
             << " = " << a[index] << endl;

        cout << "Enter new value: ";
        cin >> value;

        a[index] = value;

        cout << "Updated value = " << a[index] << endl;
    }
    catch (const out_of_range& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
