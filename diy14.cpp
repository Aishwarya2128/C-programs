
#include <iostream>
using namespace std;

class Time
{
private:
    int hh, mm;

public:
    void setTime(int h, int m)
    {
        hh = h;
        mm = m;
    }

    void display()
    {
        if (hh < 10)
            cout << "0";
        cout << hh << ":";

        if (mm < 10)
            cout << "0";
        cout << mm;
    }

    friend Time laterOf(Time t1, Time t2);
};

Time laterOf(Time t1, Time t2)
{
    int time1 = t1.hh * 60 + t1.mm;
    int time2 = t2.hh * 60 + t2.mm;

    if (time1 >= time2)
        return t1;
    else
        return t2;
}

int main()
{
    Time t1, t2, later;
    int h, m;

    cout << "Enter first time (hours minutes): ";
    cin >> h >> m;
    t1.setTime(h, m);

    cout << "Enter second time (hours minutes): ";
    cin >> h >> m;
    t2.setTime(h, m);

    later = laterOf(t1, t2);

    cout << "First time: ";
    t1.display();

    cout << "\nSecond time: ";
    t2.display();

    cout << "\nLater time: ";
    later.display();

    cout << endl;

    return 0;
}
