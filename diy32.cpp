
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Queue {
    T a[100];
    int frontIndex, rear;

public:
    Queue() {
        frontIndex = 0;
        rear = -1;
    }

    void enqueue(T x) {
        if (rear == 99) {
            cout << "Queue is Full\n";
            return;
        }

        a[++rear] = x;
        cout << x << " inserted\n";
    }

    void dequeue() {
        if (frontIndex > rear) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted: " << a[frontIndex++] << endl;
    }

    void front() {
        if (frontIndex > rear) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Front Element: " << a[frontIndex] << endl;
    }
};

int main() {
    Queue<string> q;

    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Mango");

    q.front();

    q.dequeue();
    q.front();

    return 0;
}
