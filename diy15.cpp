
#include <iostream>
using namespace std;

class Order
{
private:
    int orderID;
    static int nextID;

public:
    Order()
    {
        orderID = nextID;
        nextID++;
    }

    void display()
    {
        cout << "Order ID: " << orderID << endl;
    }
};

// Initialize static member
int Order::nextID = 1001;

int main()
{
    Order o1, o2, o3;

    cout << "Order Details:" << endl;

    o1.display();
    o2.display();
    o3.display();

    cout << "\nCreating another order:" << endl;

    Order o4;
    o4.display();

    return 0;
}
