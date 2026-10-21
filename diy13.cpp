
#include <iostream>
using namespace std;

class Counter
{
private:
    int count;
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter()
    {
        count = 0;
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter()
    {
        currentlyAlive--;
    }

    void increment()
    {
        count++;
    }

    void reset()
    {
        count = 0;
    }

    int get()
    {
        return count;
    }

    static int getTotalCreated()
    {
        return totalCreated;
    }

    static int getCurrentlyAlive()
    {
        return currentlyAlive;
    }
};

// Definition of static members
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main()
{
    Counter c1, c2;

    c1.increment();
    c1.increment();
    c2.increment();

    cout << "Counter 1 = " << c1.get() << endl;
    cout << "Counter 2 = " << c2.get() << endl;

    cout << "Total objects created = "
         << Counter::getTotalCreated() << endl;

    cout << "Objects currently alive = "
         << Counter::getCurrentlyAlive() << endl;

    {
        Counter c3, c4;

        cout << "\nAfter creating two more objects:" << endl;
        cout << "Total objects created = "
             << Counter::getTotalCreated() << endl;

        cout << "Objects currently alive = "
             << Counter::getCurrentlyAlive() << endl;
    }

    cout << "\nAfter the inner block ends:" << endl;
    cout << "Total objects created = "
         << Counter::getTotalCreated() << endl;

    cout << "Objects currently alive = "
         << Counter::getCurrentlyAlive() << endl;

    return 0;
}