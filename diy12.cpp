
#include <iostream>
using namespace std;

class Tracer
{
private:
    int id;

public:
    Tracer(int n)
    {
        id = n;
        cout << "Tracer " << id << " created." << endl;
    }

    ~Tracer()
    {
        cout << "Tracer " << id << " destroyed." << endl;
    }
};

int main()
{
    const int N = 3;

    for (int i = 1; i <= N; i++)
    {
        Tracer *t = new Tracer(i);

        cout << "Working with Tracer " << i << endl;

        delete t;  // Releases memory and calls destructor
    }

    cout << "Program finished." << endl;

    return 0;
}
